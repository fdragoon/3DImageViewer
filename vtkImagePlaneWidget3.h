#ifndef vtkImagePlaneWidget3_h
#define vtkImagePlaneWidget3_h

#include <vtkObject.h>

#include <vtkActor.h>
#include <vtkAlgorithmOutput.h>
#include <vtkCamera.h>
#include <vtkCellPicker.h>
#include <vtkDataObject.h>
#include <vtkImageActor.h>
#include <vtkImageData.h>
#include <vtkImageMapper3D.h>
#include <vtkImageMapToColors.h>
#include <vtkImagePlaneWidget.h>
#include <vtkObjectFactory.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSetGet.h>
#include <vtkWindowLevelLookupTable.h>

#define vtkGetObject3Macro(name,type)\
virtual type *Get##name##X() {\
	vtkDebugMacro(<< this->GetClassName() << " (" << this\
		<< "): returning " #name "[0] address " << this->name);\
	return this->name[0];\
};\
virtual type *Get##name##Y() {\
	vtkDebugMacro(<< this->GetClassName() << " (" << this\
		<< "): returning " #name "[1] address " << this->name);\
	return this->name[1];\
};\
virtual type *Get##name##Z() {\
	vtkDebugMacro(<< this->GetClassName() << " (" << this\
		<< "): returning " #name "[2] address " << this->name);\
	return this->name[2];\
}

class vtkImagePlaneWidget3 :public vtkObject {
public:
	static vtkImagePlaneWidget3 *New();
	vtkTypeMacro(vtkImagePlaneWidget3, vtkObject);

	vtkImagePlaneWidget3(vtkImagePlaneWidget3&) = delete;
	vtkImagePlaneWidget3 &operator=(vtkImagePlaneWidget3&) = delete;

	// Description:
	// 设置输入图像。
	virtual void SetInputConnection(vtkAlgorithmOutput* input);

	// Description:
	// 设置显示点。
	inline void SetPoint(int x, int y, int z) {
		PlaneWidget[0]->SetSliceIndex(x);
		PlaneWidget[1]->SetSliceIndex(y);
		PlaneWidget[2]->SetSliceIndex(z);
	};
	inline void SetPoint(int pos[3]) {
		PlaneWidget[0]->SetSliceIndex(pos[0]);
		PlaneWidget[1]->SetSliceIndex(pos[1]);
		PlaneWidget[2]->SetSliceIndex(pos[2]);
	};
	inline void SetX(int arg) {
		PlaneWidget[0]->SetSliceIndex(arg);
	};
	inline void SetY(int arg) {
		PlaneWidget[1]->SetSliceIndex(arg);
	};
	inline void SetZ(int arg) {
		PlaneWidget[2]->SetSliceIndex(arg);
	};

	// Description:
	// 设置渲染窗口。
	virtual void SetRenderWindow(vtkRenderWindow *arg);
	vtkGetObjectMacro(RenderWindow, vtkRenderWindow);

	// Description:
	// 设置窗口交互器。
	virtual void SetInteractor(vtkRenderWindowInteractor* iren);

	// Description:
	// 设置窗口交互器。
	vtkSetMacro(Picker, vtkCellPicker *);
	vtkGetObjectMacro(Picker, vtkCellPicker);

	// Description:
	// 获取行动器。
	vtkGetObject3Macro(ImageActor, vtkImageActor);
	vtkGetVector3Macro(ImageActor, vtkImageActor *);
	vtkGetObjectMacro(OutlineActor, vtkActor);

	// Description：
	// 获取渲染器。
	vtkGetObject3Macro(Renderer, vtkRenderer);
	vtkGetVector3Macro(Renderer, vtkRenderer *);
	vtkGetObjectMacro(Renderer3d, vtkRenderer);

	// Description:
	// 打开窗口交互器。
	inline void On() {
		for (auto &planeWidgetI : PlaneWidget)
			planeWidgetI->On();
	}

	// Description:
	// 关闭窗口交互器。
	inline void Off() {
		for (auto &planeWidgetI : PlaneWidget)
			planeWidgetI->Off();
	}

	// Description:
	// 重置镜头。
	void ResetCamera();

	// Description:
	// 渲染。
	virtual void Render();

protected:
	vtkImagePlaneWidget3();
	~vtkImagePlaneWidget3();

private:
	vtkWindowLevelLookupTable  *WindowLevelLookupTable;
	vtkOutlineFilter *Outline;
	vtkPolyDataMapper *OutlineMapper;
	vtkActor *OutlineActor;
	vtkRenderer *Renderer3d, *Renderer[3];
	vtkImagePlaneWidget *PlaneWidget[3];
	vtkImageMapToColors *ImageMapToColors[3];
	vtkImageActor *ImageActor[3];
	vtkRenderWindow *RenderWindow;
	vtkCellPicker *Picker;
};

#endif
