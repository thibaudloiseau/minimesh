#pragma once

#include <vtkSmartPointer.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkDataSet.h>

class vtkDataSet;

class Viewer
{
public:
  Viewer(void);
  ~Viewer(void) {}

  void view(vtkSmartPointer<vtkDataSet>);
};
