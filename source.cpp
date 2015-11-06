
#include <vtkCellPicker.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

//#include "vtkImageViewer3.h"
#include "vtkImagePlaneWidget3.h"
#include "vtkWindowCallback.h"


int main(int argc, char *argv[])
{
	int x = 200;
	int y = 200;
	int z = 100;

	//读取Dicom数据
	//VTK可以从文件夹中读取一系列数据，并组合为三维图像数据。
	char *dirname = argv[2];
	vtkSmartPointer<vtkDICOMImageReader> dr = vtkSmartPointer<vtkDICOMImageReader>::New();
	dr->SetDirectoryName(dirname);
	dr->Update();

	int mode = atoi(argv[1]);

	//if (mode == 1)
	//{
	//	//创建显示窗口
	//	vtkSmartPointer<vtkRenderWindow> rw = vtkSmartPointer<vtkRenderWindow> ::New();
	//	rw->SetSize(500, 500);

	//	//创建vtkImageViewer3子窗口，用以显示二维图形
	//	vtkSmartPointer<vtkImageViewer3> v = vtkSmartPointer<vtkImageViewer3>::New();
	//	//设置数据源
	//	v->SetInputConnection(dr->GetOutputPort());
	//	//设置显示坐标
	//	v->SetPoint(x, y, z);
	//	//设置渲染窗口
	//	v->SetRenderWindow(rw);

	//	//创建交互器
	//	vtkSmartPointer<vtkRenderWindowInteractor>rwi = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//	rwi->SetRenderWindow(rw);

	//	//交互器样式暂时采用vtkInteractorStyleImage
	//	vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	//	rwi->SetInteractorStyle(windowInteractorStyle);

	//	//初始化与显示
	//	rwi->Initialize();
	//	rwi->Start();
	//}
	//else
	if (mode == 2)
	{
		//vtkImageViewer2单图像实现
		vtkSmartPointer<vtkImageViewer2> v = vtkSmartPointer<vtkImageViewer2>::New();
		v->SetInputConnection(dr->GetOutputPort());
		v->SetSliceOrientationToXY();
		v->SetSlice(z);
		
		//创建交互器
		vtkSmartPointer<vtkRenderWindowInteractor>rwi = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		rwi->SetRenderWindow(v->GetRenderWindow());//-2

		//初始化与显示
		rwi->Initialize();
		rwi->Start();
	}
	else if (mode == 3)
	{
		//创建显示窗口
		vtkSmartPointer<vtkRenderWindow> rw = vtkSmartPointer<vtkRenderWindow> ::New();
		rw->SetSize(500, 500);

		//创建交互器
		vtkSmartPointer<vtkRenderWindowInteractor>rwi = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		rwi->SetRenderWindow(rw);

		//创建抓取器
		vtkSmartPointer<vtkCellPicker> picker = vtkSmartPointer<vtkCellPicker>::New();
		picker->SetTolerance(0.005);

		//创建vtkImagePlaneWidget3子窗口
		vtkSmartPointer<vtkImagePlaneWidget3> v = vtkSmartPointer<vtkImagePlaneWidget3>::New();

		//设置数据
		v->SetInputConnection(dr->GetOutputPort());
		v->SetRenderWindow(rw);
		v->SetPicker(picker);
		v->SetPoint(x, y, z);
		v->SetInteractor(rwi);

		//定义回调
		vtkSmartPointer<vtkClickCallback> cc = vtkSmartPointer<vtkClickCallback>::New();
		cc->ipw3 = v;

		//设置交互器
		rwi->RemoveAllObservers();
		rwi->AddObserver(vtkCommand::LeftButtonPressEvent, cc);

		//打开控件
		rw->Render();
		v->On();
		v->ResetCamera();
		rw->Render();
		//初始化与显示	
		rwi->Initialize();
		rwi->Start();

	}


	return 0;
}
