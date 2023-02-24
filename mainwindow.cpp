#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

using namespace std;



auto renderer = vtkSmartPointer<vtkRenderer>::New( );
auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New( );

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    renderWindow->AddRenderer(renderer);
    viewer.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "sample", false));
    ui->openGLWidget->setRenderWindow(viewer->getRenderWindow( ));
    viewer->setupInteractor(ui->openGLWidget->interactor(), ui->openGLWidget->renderWindow());
    viewer->setCameraPosition(100, -100, 100, 0, 0, 0, 0, 0, 1);
    viewer->getRenderWindow()->Render();
    ui->openGLWidget->show();
}


void MainWindow::on_actionOpen_triggered()
{
    pcl::PointCloud < pcl::PointXYZI >::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);

    pcl::io::loadPCDFile("gjs05-10 - Cloud.pcd", *cloud);


}


