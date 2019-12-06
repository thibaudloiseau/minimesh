#include <memory>

#include "viewer.hpp"



Viewer::Viewer(){}

void Viewer::view(vtkSmartPointer<vtkDataSet> ds){
auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
mapper->SetInputData(ds);

auto actor = vtkSmartPointer<vtkActor>::New();
actor->SetMapper(mapper);
actor->GetProperty()->EdgeVisibilityOn();

auto renderer = vtkSmartPointer<vtkRenderer>::New();
auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
renderWindow->AddRenderer(renderer);
auto renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
renderWindowInteractor->SetRenderWindow(renderWindow);
renderer->AddActor(actor);
renderer->SetBackground(1,1,1);
renderWindow->Render();
renderWindowInteractor->Start();

}
