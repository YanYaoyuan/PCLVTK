#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>


//VTK
#include <vtkSmartPointer.h>
#include <vtkCameraActor.h>
#include <vtkNamedColors.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkCamera.h>
#include <vtkPlanes.h>
#include <vtkMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRegularPolygonSource.h>
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);


//PCL
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include "FileIO.h"
#include "MyCloud.h"








QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;


    FileIO fileIo;
    MyCloud mycloud_xyz;

    std::vector<MyCloud> mycloud_vec;
    pcl::PointCloud<pcl::PointXYZI>::Ptr mycloud_xyzi;

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;


    void init();




};
#endif // MAINWINDOW_H
