
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

#include "vtkImageViewer3.h"




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

	////������ʾ����
	//vtkSmartPointer<vtkRenderWindow> windowsBasic = vtkSmartPointer<vtkRenderWindow> ::New();
	//windowsBasic->SetSize(500, 500);

	////����vtkImageViewer3�Ӵ��ڣ�������ʾ��άͼ��
	//vtkSmartPointer<vtkImageViewer3> viewer = vtkSmartPointer<vtkImageViewer3>::New();
	////��������Դ
	//viewer->SetInputConnection(dicomReader->GetOutputPort());
	////������ʾ����
	//viewer->SetPoint(x, y, z);
	////������Ⱦ����
	//viewer->SetRenderWindow(windowsBasic);

	//vtkImageViewer2��ͼ��ʵ��
	vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
	viewer->SetInputConnection(dicomReader->GetOutputPort());
	viewer->SetSliceOrientationToXY();
	viewer->SetSlice(100);

	//����������
	vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//windowInteractor->SetRenderWindow(windowsBasic);//-3
	windowInteractor->SetRenderWindow(viewer->GetRenderWindow());//-2
	//��������ʽ��ʱ����vtkInteractorStyleImage
	vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	windowInteractor->SetInteractorStyle(windowInteractorStyle);

	//��ʼ������ʾ
	windowInteractor->Initialize();
	windowInteractor->Start();

	return 0;
}
