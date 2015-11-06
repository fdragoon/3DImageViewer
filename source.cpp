
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

	//��ȡDicom����
	//VTK���Դ��ļ����ж�ȡһϵ�����ݣ������Ϊ��άͼ�����ݡ�
	char *dirname = argv[2];
	vtkSmartPointer<vtkDICOMImageReader> dr = vtkSmartPointer<vtkDICOMImageReader>::New();
	dr->SetDirectoryName(dirname);
	dr->Update();

	int mode = atoi(argv[1]);

	//if (mode == 1)
	//{
	//	//������ʾ����
	//	vtkSmartPointer<vtkRenderWindow> rw = vtkSmartPointer<vtkRenderWindow> ::New();
	//	rw->SetSize(500, 500);

	//	//����vtkImageViewer3�Ӵ��ڣ�������ʾ��άͼ��
	//	vtkSmartPointer<vtkImageViewer3> v = vtkSmartPointer<vtkImageViewer3>::New();
	//	//��������Դ
	//	v->SetInputConnection(dr->GetOutputPort());
	//	//������ʾ����
	//	v->SetPoint(x, y, z);
	//	//������Ⱦ����
	//	v->SetRenderWindow(rw);

	//	//����������
	//	vtkSmartPointer<vtkRenderWindowInteractor>rwi = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//	rwi->SetRenderWindow(rw);

	//	//��������ʽ��ʱ����vtkInteractorStyleImage
	//	vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	//	rwi->SetInteractorStyle(windowInteractorStyle);

	//	//��ʼ������ʾ
	//	rwi->Initialize();
	//	rwi->Start();
	//}
	//else
	if (mode == 2)
	{
		//vtkImageViewer2��ͼ��ʵ��
		vtkSmartPointer<vtkImageViewer2> v = vtkSmartPointer<vtkImageViewer2>::New();
		v->SetInputConnection(dr->GetOutputPort());
		v->SetSliceOrientationToXY();
		v->SetSlice(z);
		
		//����������
		vtkSmartPointer<vtkRenderWindowInteractor>rwi = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		rwi->SetRenderWindow(v->GetRenderWindow());//-2

		//��ʼ������ʾ
		rwi->Initialize();
		rwi->Start();
	}
	else if (mode == 3)
	{
		//������ʾ����
		vtkSmartPointer<vtkRenderWindow> rw = vtkSmartPointer<vtkRenderWindow> ::New();
		rw->SetSize(500, 500);

		//����������
		vtkSmartPointer<vtkRenderWindowInteractor>rwi = vtkSmartPointer<vtkRenderWindowInteractor>::New();
		rwi->SetRenderWindow(rw);

		//����ץȡ��
		vtkSmartPointer<vtkCellPicker> picker = vtkSmartPointer<vtkCellPicker>::New();
		picker->SetTolerance(0.005);

		//����vtkImagePlaneWidget3�Ӵ���
		vtkSmartPointer<vtkImagePlaneWidget3> v = vtkSmartPointer<vtkImagePlaneWidget3>::New();

		//��������
		v->SetInputConnection(dr->GetOutputPort());
		v->SetRenderWindow(rw);
		v->SetPicker(picker);
		v->SetPoint(x, y, z);
		v->SetInteractor(rwi);

		//����ص�
		vtkSmartPointer<vtkClickCallback> cc = vtkSmartPointer<vtkClickCallback>::New();
		cc->ipw3 = v;

		//���ý�����
		rwi->RemoveAllObservers();
		rwi->AddObserver(vtkCommand::LeftButtonPressEvent, cc);

		//�򿪿ؼ�
		rw->Render();
		v->On();
		v->ResetCamera();
		rw->Render();
		//��ʼ������ʾ	
		rwi->Initialize();
		rwi->Start();

	}


	return 0;
}
