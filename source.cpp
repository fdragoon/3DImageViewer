
#include <vtkCellPicker.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

#include "vtkImageViewer3.h"
#include "vtkImagePlaneWidget3.h"

int main(int argc, char *argv[])
{


	int x = 200;
	int y = 200;
	int z = 100;

	//��ȡDicom����
	//VTK���Դ��ļ����ж�ȡһϵ�����ݣ������Ϊ��άͼ�����ݡ�
	char dirname[100] = "..\\..\\Source\\CT2\\";
	vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
	dicomReader->SetDirectoryName(dirname);
	dicomReader->Update();

	int mode = 3;

	if (mode == 1)
	{
		//������ʾ����
		vtkSmartPointer<vtkRenderWindow> windowsBasic = vtkSmartPointer<vtkRenderWindow> ::New();
		windowsBasic->SetSize(500, 500);

		//����vtkImageViewer3�Ӵ��ڣ�������ʾ��άͼ��
		vtkSmartPointer<vtkImageViewer3> viewer = vtkSmartPointer<vtkImageViewer3>::New();
		//��������Դ
		viewer->SetInputConnection(dicomReader->GetOutputPort());
		//������ʾ����
		viewer->SetPoint(x, y, z);
		//������Ⱦ����
		viewer->SetRenderWindow(windowsBasic);


		//����������
		vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		windowInteractor->SetRenderWindow(windowsBasic);

		//��������ʽ��ʱ����vtkInteractorStyleImage
		vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
		windowInteractor->SetInteractorStyle(windowInteractorStyle);

		//��ʼ������ʾ
		windowInteractor->Initialize();
		windowInteractor->Start();
	}
	else if (mode == 2)
	{
		//vtkImageViewer2��ͼ��ʵ��
		vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
		viewer->SetInputConnection(dicomReader->GetOutputPort());
		viewer->SetSliceOrientationToXY();
		viewer->SetSlice(100);
		//����������
		vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		windowInteractor->SetRenderWindow(viewer->GetRenderWindow());//-2

		//��������ʽ��ʱ����vtkInteractorStyleImage
		vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
		windowInteractor->SetInteractorStyle(windowInteractorStyle);

		//��ʼ������ʾ
		windowInteractor->Initialize();
		windowInteractor->Start();
	}
	else if (mode==3)
	{
		//������ʾ����
		vtkSmartPointer<vtkRenderWindow> windowsBasic = vtkSmartPointer<vtkRenderWindow> ::New();
		windowsBasic->SetSize(600, 600);

		//����������
		vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		windowInteractor->SetRenderWindow(windowsBasic);

		//������Ҳ��֪����ɶ�Ķ���
		vtkSmartPointer<vtkCellPicker> picker =	vtkSmartPointer<vtkCellPicker>::New();
		picker->SetTolerance(0.005);

		//����vtkImageViewer3�Ӵ��ڣ�������ʾ��άͼ��
		vtkSmartPointer<vtkImagePlaneWidget3> viewer = vtkSmartPointer<vtkImagePlaneWidget3>::New();
	
		//��������Դ
		viewer->SetInputConnection(dicomReader->GetOutputPort());

		//���ý�����
		viewer->SetInteractor(windowInteractor);
		viewer->SetPicker(picker);

		//������ʾ����
		viewer->SetPoint(x, y, z);

		//������Ⱦ����
		viewer->SetRenderWindow(windowsBasic);

		//�򿪿ؼ�
		viewer->On();

		//��ʼ������ʾ
		windowInteractor->Initialize();
		windowInteractor->Start();

	}


	return 0;
}
