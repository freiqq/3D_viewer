#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_spinBox_x_valueChanged(int x) {
  ui->widget->set_coordinate_x(x);
}

void MainWindow::on_spinBox_y_valueChanged(int y) {
  ui->widget->set_coordinate_y(y);
}

void MainWindow::on_spinBox_z_valueChanged(int z) {
  ui->widget->set_coordinate_z(z);
}

void MainWindow::on_spinBox_x_angle_valueChanged(double arg1) {
  ui->widget->set_angle_x(arg1);
}

void MainWindow::on_spinBox_y_angle_valueChanged(double arg1) {
  ui->widget->set_angle_y(arg1);
}

void MainWindow::on_spinBox_z_angle_valueChanged(double arg1) {
  ui->widget->set_angle_z(arg1);
}

void MainWindow::on_spinBox_scale_valueChanged(double arg1) {
  ui->widget->set_scale(arg1);
}

void MainWindow::on_projection_f_clicked() {
  ui->widget->set_projection_type(1);
  settings.projection = 1;
  record_settings(settings);
}

void MainWindow::on_projection_p_clicked() {
  ui->widget->set_projection_type(0);
  settings.projection = 0;
  record_settings(settings);
}

void MainWindow::on_line_type_solid_clicked() {
  ui->widget->set_type_of_line(0);
  settings.dotted_line = 0;
  record_settings(settings);
}

void MainWindow::on_line_type_dotted_clicked() {
  ui->widget->set_type_of_line(1);
  settings.dotted_line = 1;
  record_settings(settings);
}

void MainWindow::on_display_method_none_clicked() {
  ui->widget->set_type_of_point(0);
  settings.type_of_point = 0;
  record_settings(settings);
}

void MainWindow::on_display_method_square_clicked() {
  ui->widget->set_type_of_point(1);
  settings.type_of_point = 1;
  record_settings(settings);
}

void MainWindow::on_display_method_circle_clicked() {
  ui->widget->set_type_of_point(2);
  settings.type_of_point = 2;
  record_settings(settings);
}

void MainWindow::on_spinBox_line_width_valueChanged(double width) {
  ui->widget->set_line_width(width);
  settings.line_width = width;
  record_settings(settings);
}

void MainWindow::on_spinBox_point_size_valueChanged(double size) {
  ui->widget->set_point_size(size);
  settings.point_size = size;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_line_r_valueChanged(int r) {
  ui->widget->set_color_line_r(r);
  settings.color_of_line_r = r;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_line_g_valueChanged(int g) {
  ui->widget->set_color_line_g(g);
  settings.color_of_line_g = g;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_line_b_valueChanged(int b) {
  ui->widget->set_color_line_b(b);
  settings.color_of_line_b = b;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_back_r_valueChanged(int r) {
  ui->widget->set_color_back_r(r);
  settings.color_of_back_r = r;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_back_g_valueChanged(int g) {
  ui->widget->set_color_back_g(g);
  settings.color_of_back_g = g;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_back_b_valueChanged(int b) {
  ui->widget->set_color_back_b(b);
  settings.color_of_back_b = b;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_point_r_valueChanged(int r) {
  ui->widget->set_color_point_r(r);
  settings.color_of_point_r = r;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_point_g_valueChanged(int g) {
  ui->widget->set_color_point_g(g);
  settings.color_of_point_g = g;
  record_settings(settings);
}

void MainWindow::on_spinBox_color_point_b_valueChanged(int b) {
  ui->widget->set_color_point_b(b);
  settings.color_of_point_b = b;
  record_settings(settings);
}
