#include "vtkWindowCallback.h"

vtkStandardNewMacro(vtkClickCallback);

void vtkClickCallback::Execute(vtkObject * caller, unsigned long, void *) {
	vtkRenderWindowInteractor *rwi = dynamic_cast<vtkRenderWindowInteractor *>(caller);
	vtkCellPicker *cp = ipw3->GetPicker();
	int cursorPos[3];
	rwi->GetEventPosition(cursorPos);
	int imagePos[3];

	if (cp->Pick(static_cast<double>(cursorPos[0]), static_cast<double>(cursorPos[1]), 0, ipw3->GetRendererX()))
	{
		cp->GetPointIJK(imagePos);
		ipw3->SetY(imagePos[0]);
		ipw3->SetZ(imagePos[1]);
		ipw3->Render();
	}
	else if (cp->Pick(static_cast<double>(cursorPos[0]), static_cast<double>(cursorPos[1]), 0, ipw3->GetRendererY())) {
		cp->GetPointIJK(imagePos);
		ipw3->SetZ(imagePos[0]);
		ipw3->SetX(imagePos[1]);
		ipw3->Render();
	}
	else if (cp->Pick(static_cast<double>(cursorPos[0]), static_cast<double>(cursorPos[1]), 0, ipw3->GetRendererZ())) {
		cp->GetPointIJK(imagePos);
		ipw3->SetX(imagePos[0]);
		ipw3->SetY(imagePos[1]);
		ipw3->Render();
	}
}

