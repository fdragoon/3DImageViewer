
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>




int main(int argc, char *argv[])
{


	int x = 60;
	int y = 70;
	int z = 80;

	//读取Dicom数据
	//VTK可以从文件夹中读取一系列数据，并组合为三维图像数据。
	char dirname[100] = "..\\..\\Source\\CT2\\";
	vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
	dicomReader->SetDirectoryName(dirname);
	dicomReader->Update();

	//创建显示窗口
	vtkSmartPointer<vtkRenderWindow> windowsBasic = vtkSmartPointer<vtkRenderWindow> ::New();
	windowsBasic->SetSize(500, 500);

	//创建vtkImageViewer2子窗口，用以显示二维图形
	//注意，由于需要变更显示窗口，因此要将vtkImageViewer2的窗口重新定向到显示窗口，
	//同时显示窗口中添加该子窗口的渲染器。
	vtkSmartPointer<vtkImageViewer2> viewerXY = vtkSmartPointer<vtkImageViewer2>::New();
	viewerXY->SetInputConnection(dicomReader->GetOutputPort());
	viewerXY->SetSliceOrientationToXY();
	viewerXY->SetSlice(z);
	viewerXY->GetRenderer()->SetViewport(0, 0.5, 0.5, 1);
	viewerXY->SetRenderWindow(windowsBasic);
	windowsBasic->AddRenderer(viewerXY->GetRenderer());

	vtkSmartPointer<vtkImageViewer2> viewerYZ = vtkSmartPointer<vtkImageViewer2>::New();
	viewerYZ->SetInputConnection(dicomReader->GetOutputPort());
	viewerYZ->SetSliceOrientationToYZ();
	viewerYZ->SetSlice(x);
	viewerYZ->GetRenderer()->SetViewport(0.5, 0.5, 1, 1);
	viewerYZ->SetRenderWindow(windowsBasic);
	windowsBasic->AddRenderer(viewerXY->GetRenderer());

	vtkSmartPointer<vtkImageViewer2> viewerXZ = vtkSmartPointer<vtkImageViewer2>::New();
	viewerXZ->SetInputConnection(dicomReader->GetOutputPort());
	viewerXZ->SetSliceOrientationToXZ();
	viewerXZ->SetSlice(y);
	viewerXZ->GetRenderer()->SetViewport(0, 0, 0.5, 0.5);
	viewerXZ->SetRenderWindow(windowsBasic);
	windowsBasic->AddRenderer(viewerXZ->GetRenderer());

	//创建交互器
	vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	windowInteractor->SetRenderWindow(windowsBasic);
	//交互器样式暂时采用vtkInteractorStyleImage
	vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	windowInteractor->SetInteractorStyle(windowInteractorStyle);

	//初始化与显示
	windowInteractor->Initialize();
	windowInteractor->Start();

	return 0;
}
