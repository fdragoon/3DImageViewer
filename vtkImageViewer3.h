#include "vtkObject.h"

#include "vtkAlgorithmOutput.h"
#include "vtkImageViewer2.h"
#include "vtkRenderWindow.h"

class vtkImageViewer3 :public vtkObject
{
public:
	static vtkImageViewer3 *New();
	vtkTypeMacro(vtkImageViewer3, vtkObject);


	vtkImageViewer3(vtkImageViewer3&) = delete;
	vtkImageViewer3 &operator=(vtkImageViewer3&) = delete;


	// Description:
	// 设置输入图像。
	virtual void SetInputConnection(vtkAlgorithmOutput* input);

	// Description:
	// 设置显示点。
	virtual void SetPoint(int x, int y, int z);

	// Description:
	// 设置渲染窗口。
	virtual void SetRenderWindow(vtkRenderWindow *arg);

protected:
	vtkImageViewer3();
	~vtkImageViewer3();

public:
	vtkImageViewer2 *viewerXY, *viewerYZ, *viewerXZ;

};
