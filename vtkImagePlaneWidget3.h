#include <vtkObject.h>

#include <vtkActor.h>
#include <vtkAlgorithmOutput.h>
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
#include <vtkWindowLevelLookupTable.h>


class vtkImagePlaneWidget3 :public vtkObject
{
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
	virtual void SetPoint(int x, int y, int z);

	// Description:
	// 设置渲染窗口。
	virtual void SetRenderWindow(vtkRenderWindow *arg);

	// Description:
	// 设置窗口交互器。
	virtual void SetInteractor(vtkRenderWindowInteractor* iren);

	// Description:
	// 设置窗口交互器。
	void SetPicker(vtkAbstractPropPicker*);

	// Description:
	// 获取vtkImageActor

	// Description:
	// 打开窗口交互器。
	inline void On() {
		for (auto &planeWidgetI: planeWidget)
			planeWidgetI->On();
	}

	// Description:
	// 关闭窗口交互器。
	inline void Off() {
		for (auto &planeWidgetI : planeWidget)
			planeWidgetI->Off();
	}

protected:
	vtkImagePlaneWidget3();
	~vtkImagePlaneWidget3();

private:
	vtkWindowLevelLookupTable  *windowLevel;
	vtkOutlineFilter *outline;
	vtkPolyDataMapper *outlineMapper;
	vtkActor *outlineActor;
	vtkRenderer *ren3D, *ren[3];
	vtkImagePlaneWidget *planeWidget[3];
	vtkImageMapToColors *colorMap[3];
	vtkImageActor *imageActor[3];

};


