
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

	//��ȡDicom����
	//VTK���Դ��ļ����ж�ȡһϵ�����ݣ������Ϊ��άͼ�����ݡ�
	char dirname[100] = "..\\..\\Source\\CT2\\";
	vtkSmartPointer<vtkDICOMImageReader> dicomReader = vtkSmartPointer<vtkDICOMImageReader>::New();
	dicomReader->SetDirectoryName(dirname);
	dicomReader->Update();

	//������ʾ����
	vtkSmartPointer<vtkRenderWindow> windowsBasic = vtkSmartPointer<vtkRenderWindow> ::New();
	windowsBasic->SetSize(500, 500);

	//����vtkImageViewer2�Ӵ��ڣ�������ʾ��άͼ��
	//ע�⣬������Ҫ�����ʾ���ڣ����Ҫ��vtkImageViewer2�Ĵ������¶�����ʾ���ڣ�
	//ͬʱ��ʾ��������Ӹ��Ӵ��ڵ���Ⱦ����
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

	//����������
	vtkSmartPointer<vtkRenderWindowInteractor>windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	windowInteractor->SetRenderWindow(windowsBasic);
	//��������ʽ��ʱ����vtkInteractorStyleImage
	vtkSmartPointer<vtkInteractorStyleImage>windowInteractorStyle = vtkSmartPointer<vtkInteractorStyleImage>::New();
	windowInteractor->SetInteractorStyle(windowInteractorStyle);

	//��ʼ������ʾ
	windowInteractor->Initialize();
	windowInteractor->Start();

	return 0;
}
