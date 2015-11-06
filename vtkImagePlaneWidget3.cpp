#include "vtkImagePlaneWidget3.h"

vtkStandardNewMacro(vtkImagePlaneWidget3);

void vtkImagePlaneWidget3::SetInputConnection(vtkAlgorithmOutput * input) {
	Outline->SetInputConnection(input);

	for (int numi = 0; numi < 3; numi++) {
		auto &PlaneWidgetI = PlaneWidget[numi];
		PlaneWidgetI->SetInputConnection(input);
		PlaneWidgetI->SetPlaneOrientation(numi);
	}
}

void vtkImagePlaneWidget3::SetRenderWindow(vtkRenderWindow * arg) {

	RenderWindow = arg;
	arg->AddRenderer(Renderer3d);
	for (auto &RendererI : Renderer)
		arg->AddRenderer(RendererI);
}

void vtkImagePlaneWidget3::SetInteractor(vtkRenderWindowInteractor * iren) {
	for (auto &PlaneWidgetI : PlaneWidget)
		PlaneWidgetI->SetInteractor(iren);
}

void vtkImagePlaneWidget3::ResetCamera() {
	Renderer3d->GetActiveCamera()->Elevation(110);
	Renderer3d->GetActiveCamera()->SetViewUp(0, 0, -1);
	Renderer3d->GetActiveCamera()->Azimuth(45);
	Renderer3d->GetActiveCamera()->Dolly(1.15);
	Renderer3d->ResetCamera();
	for (auto &RendererI : Renderer)
		RendererI->ResetCamera();
}

void vtkImagePlaneWidget3::Render() {
	RenderWindow->Render();
}

vtkImagePlaneWidget3::vtkImagePlaneWidget3()
{
	WindowLevelLookupTable = vtkWindowLevelLookupTable::New();

	Outline = vtkOutlineFilter::New();
	OutlineMapper = vtkPolyDataMapper::New();
	OutlineMapper->SetInputConnection(Outline->GetOutputPort());
	OutlineActor = vtkActor::New();
	OutlineActor->SetMapper(OutlineMapper);

	Renderer3d = vtkRenderer::New();
	Renderer3d->AddActor(OutlineActor);


	for (int numi = 0; numi < 3; numi++)
	{
		Renderer[numi] = vtkRenderer::New();

		auto &PlaneWidgetI = PlaneWidget[numi];
		PlaneWidgetI = vtkImagePlaneWidget::New();
		PlaneWidgetI->RestrictPlaneToVolumeOn();
		PlaneWidgetI->TextureInterpolateOff();
		PlaneWidgetI->SetResliceInterpolateToNearestNeighbour();
		PlaneWidgetI->SetLookupTable(WindowLevelLookupTable);
		PlaneWidgetI->DisplayTextOn();

		auto &ImageMapToColorsI = ImageMapToColors[numi];
		ImageMapToColorsI = vtkImageMapToColors::New();
		ImageMapToColors[numi]->SetInputData(PlaneWidget[numi]->GetResliceOutput());
		ImageMapToColorsI->PassAlphaToOutputOff();
		ImageMapToColorsI->SetActiveComponent(0);
		ImageMapToColorsI->SetOutputFormatToLuminance();
		ImageMapToColorsI->SetLookupTable(WindowLevelLookupTable);

		ImageActor[numi] = vtkImageActor::New();
		ImageActor[numi]->GetMapper()->SetInputConnection(ImageMapToColors[numi]->GetOutputPort());
		Renderer[numi]->AddActor(ImageActor[numi]);
	}
	Renderer3d->SetViewport(0, 0, 0.5, 0.5);
	Renderer3d->SetBackground(0.1, 0.2, 0.2);
	Renderer[0]->SetViewport(0, 0.5, 0.5, 1);
	Renderer[0]->SetBackground(0.2, 0.1, 0.1);
	Renderer[1]->SetViewport(0.5, 0.5, 1, 1);
	Renderer[1]->SetBackground(0.1, 0.2, 0.1);
	Renderer[2]->SetViewport(0.5, 0, 1, 0.5);
	Renderer[2]->SetBackground(0.1, 0.1, 0.2);

}

vtkImagePlaneWidget3::~vtkImagePlaneWidget3()
{
	if (WindowLevelLookupTable)
		WindowLevelLookupTable->Delete();
	if (Outline)
		Outline->Delete();
	if (OutlineMapper)
		OutlineMapper->Delete();
	if (OutlineActor)
		OutlineActor->Delete();

	if (Renderer3d)
		Renderer3d->Delete();
	if (Renderer[0])
		for (auto *RendererI : Renderer)
			RendererI->Delete();
	if (PlaneWidget[0])
		for (auto *PlaneWidgetI : PlaneWidget)
			PlaneWidgetI->Delete();
	if (ImageMapToColors[0])
		for (auto *ImageMapToColorsI : ImageMapToColors)
			ImageMapToColorsI->Delete();
	if (ImageActor[0])
		for (auto *ImageActorI : ImageActor)
			ImageActorI->Delete();
}
