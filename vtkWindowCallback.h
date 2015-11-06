
#include <vtkCellPicker.h>
#include <vtkCommand.h>
#include <vtkRenderWindowInteractor.h>

#include "vtkImagePlaneWidget3.h"

class vtkClickCallback :public vtkCommand {
public:
	static vtkClickCallback *New();

	void Execute(vtkObject *caller, unsigned long ev, void *callData);

	vtkClickCallback() {
	};
	~vtkClickCallback() {
	};

	vtkImagePlaneWidget3 *ipw3;
};
