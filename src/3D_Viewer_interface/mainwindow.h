#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QTimer>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "qgifimage.h"
#include "viewer.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../3D_Viewer_backend/s21_common.h"
#include "../3D_Viewer_backend/s21_memory_handling.h"
#include "../3D_Viewer_backend/s21_parsers.h"
#include "../3D_Viewer_backend/s21_settings_bonus.h"
#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 private:
  settings_t settings = {0};

  int time;
  QTimer* timer;
  QImage* image;
  QGifImage* gif;
  QString gifPath;

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:

  void enable_buttons();
  void adjust();
  void gif_f();
  void on_button_open_file_clicked();
  void on_button_create_gif_clicked();
  void on_button_create_img_clicked();
  void on_spinBox_x_valueChanged(int x);
  void on_spinBox_y_valueChanged(int y);
  void on_spinBox_z_valueChanged(int z);
  void on_spinBox_x_angle_valueChanged(double arg1);
  void on_spinBox_y_angle_valueChanged(double arg1);
  void on_spinBox_z_angle_valueChanged(double arg1);
  void on_spinBox_scale_valueChanged(double arg1);

  void on_line_type_solid_clicked();
  void on_line_type_dotted_clicked();

  void on_projection_f_clicked();
  void on_projection_p_clicked();

  void on_display_method_none_clicked();
  void on_display_method_square_clicked();
  void on_display_method_circle_clicked();
  void on_spinBox_line_width_valueChanged(double width);
  void on_spinBox_point_size_valueChanged(double size);

  void on_spinBox_color_line_r_valueChanged(int r);
  void on_spinBox_color_line_g_valueChanged(int g);
  void on_spinBox_color_line_b_valueChanged(int b);

  void on_spinBox_color_back_r_valueChanged(int r);
  void on_spinBox_color_back_g_valueChanged(int g);
  void on_spinBox_color_back_b_valueChanged(int b);

  void on_spinBox_color_point_r_valueChanged(int r);
  void on_spinBox_color_point_g_valueChanged(int g);
  void on_spinBox_color_point_b_valueChanged(int b);

 private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
