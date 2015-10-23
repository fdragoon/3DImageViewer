#include "vtkImageViewer3.h"

#include "vtkAlgorithmOutput.h"
#include "vtkImageViewer2.h"
#include "vtkObjectFactory.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"

vtkStandardNewMacro(vtkImageViewer3);

vtkImageViewer3::vtkImageViewer3()
{
	this->viewerXY = vtkImageViewer2::New();
	this->viewerYZ = vtkImageViewer2::New();
	this->viewerXZ = vtkImageViewer2::New();
}

vtkImageViewer3::~vtkImageViewer3()
{
	if (this->viewerXY)
		this->viewerXY->Delete();
	
	if (this->viewerYZ)
		this->viewerYZ->Delete();

	if (this->viewerXZ)
		this->viewerXZ->Delete();
}

void vtkImageViewer3::SetInputConnection(vtkAlgorithmOutput * input)
{
	viewerXY->SetInputConnection(input);
	viewerXY->SetSliceOrientationToXY();
	viewerXY->GetRenderer()->SetViewport(0, 0.5, 0.5, 1);

	viewerYZ->SetInputConnection(input);
	viewerYZ->SetSliceOrientationToYZ();
	viewerYZ->GetRenderer()->SetViewport(0.5, 0.5, 1, 1);

	viewerXZ->SetInputConnection(input);
	viewerXZ->SetSliceOrientationToXZ();
	viewerXZ->GetRenderer()->SetViewport(0, 0, 0.5, 0.5);

}

void vtkImageViewer3::SetPoint(int x, int y, int z)
{
	viewerXY->SetSlice(x);
	viewerYZ->SetSlice(y);
	viewerXZ->SetSlice(z);
}

void vtkImageViewer3::SetRenderWindow(vtkRenderWindow * arg)
{
	viewerXY->SetRenderWindow(arg);
	viewerYZ->SetRenderWindow(arg);
	viewerXZ->SetRenderWindow(arg);

	arg->AddRenderer(viewerXY->GetRenderer());
	arg->AddRenderer(viewerYZ->GetRenderer());
	arg->AddRenderer(viewerXZ->GetRenderer());
}
