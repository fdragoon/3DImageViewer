#include "vtkImagePlaneWidget3.h"

//#include "vtkSmartPointer.h"
//#include "vtkActor.h"
//#include "vtkCamera.h"
//#include "vtkCellPicker.h"
//#include "vtkCommand.h"
//#include "vtkImageActor.h"
//
//#include "vtkImagePlaneWidget.h"
//#include "vtkImageReader.h"
//#include "vtkInteractorEventRecorder.h"
//#include "vtkLookupTable.h"
//#include "vtkOutlineFilter.h"
//#include "vtkPolyDataMapper.h"
//#include "vtkProperty.h"
//#include "vtkRenderWindow.h"
//#include "vtkRenderWindowInteractor.h"
//#include "vtkRenderer.h"
//#include "vtkDICOMImageReader.h"

//#include "vtkImageSlice.h"
//#include "vtkImageProperty.h"


//----------------------------------------------------------------------------

vtkStandardNewMacro(vtkImagePlaneWidget3);

//int imagePlaneWidget3()
//{
//	char* fname = "..\\..\\Source\\CT2\\";
//	int x = 100, y = 100, z = 50;
//
//	vtkSmartPointer<vtkDICOMImageReader> dicomReader =
//		vtkSmartPointer<vtkDICOMImageReader>::New();
//	dicomReader->SetDirectoryName(fname);
//	dicomReader->Update();
//
//	vtkSmartPointer<vtkOutlineFilter> outline =
//		vtkSmartPointer<vtkOutlineFilter>::New();
//	outline->SetInputConnection(dicomReader->GetOutputPort());//
//
//	vtkSmartPointer<vtkPolyDataMapper> outlineMapper =
//		vtkSmartPointer<vtkPolyDataMapper>::New();
//	outlineMapper->SetInputConnection(outline->GetOutputPort());//
//
//	vtkSmartPointer<vtkActor> outlineActor =
//		vtkSmartPointer<vtkActor>::New();
//	outlineActor->SetMapper(outlineMapper);//
//
//	vtkSmartPointer<vtkRenderer> ren3D =
//		vtkSmartPointer<vtkRenderer>::New();
//	vtkSmartPointer<vtkRenderer> renX =
//		vtkSmartPointer<vtkRenderer>::New();
//	vtkSmartPointer<vtkRenderer> renY =
//		vtkSmartPointer<vtkRenderer>::New();
//	vtkSmartPointer<vtkRenderer> renZ =
//		vtkSmartPointer<vtkRenderer>::New();
//
//	vtkSmartPointer<vtkRenderWindow> renWin =
//		vtkSmartPointer<vtkRenderWindow>::New();
//	//renWin->SetMultiSamples(0);
//	renWin->AddRenderer(renZ);//
//	renWin->AddRenderer(renY);//
//	renWin->AddRenderer(renX);//
//	renWin->AddRenderer(ren3D);//
//
//	vtkSmartPointer<vtkRenderWindowInteractor> iren =
//		vtkSmartPointer<vtkRenderWindowInteractor>::New();
//	iren->SetRenderWindow(renWin);
//
//	vtkSmartPointer<vtkCellPicker> picker =
//		vtkSmartPointer<vtkCellPicker>::New();
//	picker->SetTolerance(0.005);
//
//	vtkSmartPointer<vtkProperty> ipwProp =
//		vtkSmartPointer<vtkProperty>::New();
//	//assign default props to the ipw's texture plane actor
//
//	//vtkSmartPointer<vtkImagePlaneWidget> planeWidgetX =
//	//	vtkSmartPointer<vtkImagePlaneWidget>::New();
//	//planeWidgetX->SetInteractor(iren);//
//	//planeWidgetX->SetKeyPressActivationValue('x');
//	//planeWidgetX->SetPicker(picker);
//	//planeWidgetX->RestrictPlaneToVolumeOn();//
//	//planeWidgetX->GetPlaneProperty()->SetColor(1, 0, 0);
//	//planeWidgetX->SetTexturePlaneProperty(ipwProp);
//	//planeWidgetX->TextureInterpolateOff();//
//	//planeWidgetX->SetResliceInterpolateToNearestNeighbour();//
//	//planeWidgetX->SetInputConnection(dicomReader->GetOutputPort());//
//	//planeWidgetX->SetPlaneOrientationToXAxes();//
//	//planeWidgetX->SetSliceIndex(x);
//	//planeWidgetX->DisplayTextOn();//
//	//planeWidgetX->On();//
//
//	vtkSmartPointer<vtkImagePlaneWidget> planeWidgetX =
//		vtkSmartPointer<vtkImagePlaneWidget>::New();
//	planeWidgetX->RestrictPlaneToVolumeOn();//
//	planeWidgetX->TextureInterpolateOff();//
//	planeWidgetX->SetResliceInterpolateToNearestNeighbour();//
//	planeWidgetX->DisplayTextOn();//
//
//	planeWidgetX->SetInputConnection(dicomReader->GetOutputPort());//
//	planeWidgetX->SetPlaneOrientationToXAxes();//
//
//	planeWidgetX->SetInteractor(iren);//
//	planeWidgetX->On();//
//
//
//	planeWidgetX->SetPicker(picker);
//
//	//planeWidgetX->SetKeyPressActivationValue('x');
//	//planeWidgetX->GetPlaneProperty()->SetColor(1, 0, 0);
//	//planeWidgetX->SetTexturePlaneProperty(ipwProp);
//	planeWidgetX->SetSliceIndex(x);
//
//	vtkSmartPointer<vtkImagePlaneWidget> planeWidgetY =
//		vtkSmartPointer<vtkImagePlaneWidget>::New();
//	planeWidgetY->SetInteractor(iren);
//	planeWidgetY->SetKeyPressActivationValue('y');
//	planeWidgetY->SetPicker(picker);
//	planeWidgetY->GetPlaneProperty()->SetColor(1, 1, 0);
//	planeWidgetY->SetTexturePlaneProperty(ipwProp);
//	planeWidgetY->TextureInterpolateOff();
//	planeWidgetY->SetResliceInterpolateToNearestNeighbour();
//	planeWidgetY->SetInputConnection(dicomReader->GetOutputPort());
//	planeWidgetY->SetPlaneOrientationToYAxes();
//	planeWidgetY->SetSlicePosition(y);
//	planeWidgetY->SetLookupTable(planeWidgetX->GetLookupTable());//?
//	planeWidgetY->DisplayTextOn();
//	planeWidgetY->On();
//
//	vtkSmartPointer<vtkImagePlaneWidget> planeWidgetZ =
//		vtkSmartPointer<vtkImagePlaneWidget>::New();
//	planeWidgetZ->SetInteractor(iren);
//	planeWidgetZ->SetKeyPressActivationValue('z');
//	planeWidgetZ->SetPicker(picker);
//	planeWidgetZ->GetPlaneProperty()->SetColor(0, 0, 1);
//	planeWidgetZ->SetTexturePlaneProperty(ipwProp);
//	planeWidgetZ->TextureInterpolateOff();
//	planeWidgetZ->SetResliceInterpolateToNearestNeighbour();
//	planeWidgetZ->SetInputConnection(dicomReader->GetOutputPort());
//	planeWidgetZ->SetPlaneOrientationToZAxes();
//	planeWidgetZ->SetSliceIndex(z);
//	planeWidgetZ->SetLookupTable(planeWidgetX->GetLookupTable());
//	planeWidgetZ->DisplayTextOn();
//	planeWidgetZ->On();
//
//	// Add a 2D image to test the GetReslice method
//	//
//	vtkSmartPointer<vtkImageMapToColors> colorMapX =
//		vtkSmartPointer<vtkImageMapToColors>::New();
//	colorMapX->PassAlphaToOutputOff();//
//	colorMapX->SetActiveComponent(0);//
//	colorMapX->SetOutputFormatToLuminance();//
//	colorMapX->SetInputData(planeWidgetX->GetResliceOutput());//
//	colorMapX->SetLookupTable(planeWidgetX->GetLookupTable());//?
//
//	vtkSmartPointer<vtkImageMapToColors> colorMapY =
//		vtkSmartPointer<vtkImageMapToColors>::New();
//	colorMapY->PassAlphaToOutputOff();
//	colorMapY->SetActiveComponent(0);
//	colorMapY->SetOutputFormatToLuminance();
//	colorMapY->SetInputData(planeWidgetY->GetResliceOutput());
//	colorMapY->SetLookupTable(planeWidgetX->GetLookupTable());
//
//	vtkSmartPointer<vtkImageMapToColors> colorMapZ =
//		vtkSmartPointer<vtkImageMapToColors>::New();
//	colorMapZ->PassAlphaToOutputOff();
//	colorMapZ->SetActiveComponent(0);
//	colorMapZ->SetOutputFormatToLuminance();
//	colorMapZ->SetInputData(planeWidgetZ->GetResliceOutput());
//	colorMapZ->SetLookupTable(planeWidgetX->GetLookupTable());
//
//	vtkSmartPointer<vtkImageActor> imageActorX = vtkSmartPointer<vtkImageActor>::New();
//	imageActorX->GetMapper()->SetInputConnection(colorMapX->GetOutputPort());//
//
//	vtkSmartPointer<vtkImageActor> imageActorY = vtkSmartPointer<vtkImageActor>::New();
//	imageActorY->GetMapper()->SetInputConnection(colorMapY->GetOutputPort());
//
//	vtkSmartPointer<vtkImageActor> imageActorZ = vtkSmartPointer<vtkImageActor>::New();
//	imageActorZ->GetMapper()->SetInputConnection(colorMapZ->GetOutputPort());
//
//
//	// Add the actors
//	//
//	ren3D->AddActor(outlineActor);//
//	renX->AddActor(imageActorX);//
//	renY->AddActor(imageActorY);
//	renZ->AddActor(imageActorZ);
//
//	ren3D->SetBackground(0.1, 0.2, 0.2);
//	renX->SetBackground(0.2, 0.1, 0.1);
//	renY->SetBackground(0.1, 0.2, 0.1);
//	renZ->SetBackground(0.1, 0.1, 0.2);
//
//	renWin->SetSize(600, 600);
//
//	ren3D->SetViewport(0, 0, 0.5, 0.5);
//	renX->SetViewport(0, 0.5, 0.5, 1);
//	renY->SetViewport(0.5, 0.5, 1, 1);
//	renZ->SetViewport(0.5, 0, 1, 0.5);
//
//
//
//	iren->Initialize();
//	iren->Start();
//
//	return EXIT_SUCCESS;
//}


void vtkImagePlaneWidget3::SetInputConnection(vtkAlgorithmOutput * input)
{
	outline->SetInputConnection(input);

	for (int numi = 0; numi < 3; numi++)
	{
		auto &planeWidgetI = planeWidget[numi];
		planeWidgetI->SetInputConnection(input);
		planeWidgetI->SetPlaneOrientation(numi);

		colorMap[numi]->SetInputData(planeWidget[numi]->GetResliceOutput());

		imageActor[numi]->GetMapper()->SetInputConnection(colorMap[numi]->GetOutputPort());
	}
}

void vtkImagePlaneWidget3::SetPoint(int x, int y, int z)
{
	planeWidget[0]->SetSliceIndex(x);
	planeWidget[1]->SetSliceIndex(y);
	planeWidget[2]->SetSliceIndex(z);
}

void vtkImagePlaneWidget3::SetRenderWindow(vtkRenderWindow * arg)
{
	arg->AddRenderer(ren3D);
	for (auto &renI : ren)
		arg->AddRenderer(renI);
	ren3D->SetViewport(0, 0, 0.5, 0.5);
	ren3D->SetBackground(0.1, 0.2, 0.2);
	ren[0]->SetViewport(0, 0.5, 0.5, 1);
	ren[0]->SetBackground(0.2, 0.1, 0.1);
	ren[1]->SetViewport(0.5, 0.5, 1, 1);
	ren[1]->SetBackground(0.1, 0.2, 0.1);
	ren[2]->SetViewport(0.5, 0, 1, 0.5);
	ren[2]->SetBackground(0.1, 0.1, 0.2);
}

void vtkImagePlaneWidget3::SetInteractor(vtkRenderWindowInteractor * iren)
{
	for (auto &planeWidgetI : planeWidget)
		planeWidgetI->SetInteractor(iren);
}

void vtkImagePlaneWidget3::SetPicker(vtkAbstractPropPicker * arg)
{
	planeWidget[0]->SetPicker(arg);
	planeWidget[1]->SetPicker(arg);
	planeWidget[2]->SetPicker(arg);

}

vtkImagePlaneWidget3::vtkImagePlaneWidget3()
{
	windowLevel = vtkWindowLevelLookupTable::New();

	outline = vtkOutlineFilter::New();
	outlineMapper = vtkPolyDataMapper::New();
	outlineMapper->SetInputConnection(outline->GetOutputPort());
	outlineActor = vtkActor::New();
	outlineActor->SetMapper(outlineMapper);

	ren3D = vtkRenderer::New();
	ren3D->AddActor(outlineActor);

	for (int numi = 0; numi < 3; numi++)
	{
		ren[numi] = vtkRenderer::New();

		auto &planeWidgetI = planeWidget[numi];
		planeWidgetI = vtkImagePlaneWidget::New();
		planeWidgetI->RestrictPlaneToVolumeOn();
		planeWidgetI->TextureInterpolateOff();
		planeWidgetI->SetResliceInterpolateToNearestNeighbour();
		planeWidgetI->SetLookupTable(windowLevel);
		planeWidgetI->DisplayTextOn();

		auto &colorMapI = colorMap[numi];
		colorMapI = vtkImageMapToColors::New();
		colorMapI->PassAlphaToOutputOff();
		colorMapI->SetActiveComponent(0);
		colorMapI->SetOutputFormatToLuminance();
		colorMapI->SetLookupTable(windowLevel);

		imageActor[numi] = vtkImageActor::New();
		ren[numi]->AddActor(imageActor[numi]);
	}
}

vtkImagePlaneWidget3::~vtkImagePlaneWidget3()
{
	if (windowLevel)
		windowLevel->Delete();
	if (outline)
		outline->Delete();
	if (outlineMapper)
		outlineMapper->Delete();
	if (outlineActor)
		outlineActor->Delete();

	if (ren3D)
		ren3D->Delete();
	if (ren[0])
		for (auto *renI : ren)
			renI->Delete();
	if (planeWidget[0])
		for (auto *planeWidgetI : planeWidget)
			planeWidgetI->Delete();
	if (colorMap[0])
		for (auto *colorMapI : colorMap)
			colorMapI->Delete();
	if (imageActor[0])
		for (auto *imageActorI : imageActor)
			imageActorI->Delete();
}
