#include "mainwindow.h"

#include "qgifimage.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  open_settings(&settings);
  ui->setupUi(this);
  adjust();

  this->setStyleSheet("background-color:rgb(42,43,42);");
  this->setFixedSize(700, 1230);
}

void MainWindow::on_button_open_file_clicked() {
  data_t data = {0};
  int type_of_line = 0;
  QString file_name = QFileDialog::getOpenFileName(
      this, "Open a file", "./obj_templates/", "(*.obj)");
  ui->input_filename->setText(file_name);
  QByteArray temp = file_name.toLocal8Bit();
  char* file_name_str = temp.data();
  strlcpy(file_name_str, temp, file_name.length() + 1);
  if (data.count_of_facets > 0 && data.count_of_vertexes > 0) {
    free_memory(&data);
  }
  FILE* fp = fopen(file_name_str, "r");
  if (fp) {
    quantity_parser(&data, fp);
    allocate_memory(&data);
    polygon_parser(&data, fp);
    fclose(fp);
    if (data.count_of_facets && data.count_of_vertexes) { // refactor
      ui->widget->set_data(data);
      ui->lineEdit->setText("Количество вершин - " +
                            QString::number(data.count_of_vertexes - 1) +
                            "\t\t" + "Количество граней - " +
                            QString::number(data.count_of_facets - 1));
      MainWindow::enable_buttons();
    } else {
      ui->input_filename->setText(Incorrect file);
//      ui->
    }
  }
}

void MainWindow::adjust() {
  ui->spinBox_color_line_r->setValue(settings.color_of_line_r);
  ui->spinBox_color_line_g->setValue(settings.color_of_line_g);
  ui->spinBox_color_line_b->setValue(settings.color_of_line_b);
  ui->spinBox_color_back_r->setValue(settings.color_of_back_r);
  ui->spinBox_color_back_g->setValue(settings.color_of_back_g);
  ui->spinBox_color_back_b->setValue(settings.color_of_back_b);
  ui->spinBox_color_point_r->setValue(settings.color_of_point_r);
  ui->spinBox_color_point_g->setValue(settings.color_of_point_g);
  ui->spinBox_color_point_b->setValue(settings.color_of_point_b);
  ui->spinBox_point_size->setValue(settings.point_size);
  ui->spinBox_line_width->setValue(settings.line_width);
  if (settings.dotted_line) {
    ui->line_type_dotted->setChecked(true);
    ui->widget->set_type_of_line(1);
  } else {
    ui->line_type_solid->setChecked(true);
    ui->widget->set_type_of_line(0);
  }
  if (settings.type_of_point == 1) {
    ui->display_method_square->setChecked(true);
    ui->widget->set_type_of_point(1);
  } else if (settings.type_of_point == 2) {
    ui->display_method_circle->setChecked(true);
    ui->widget->set_type_of_point(2);
  }
  if (settings.projection) {
    ui->projection_f->setChecked(true);
    ui->widget->set_projection_type(1);
  } else {
    ui->projection_p->setChecked(true);
    ui->widget->set_projection_type(0);
  }
}

void MainWindow::enable_buttons() {
  ui->spinBox_x->setValue(0);
  ui->spinBox_y->setValue(0);
  ui->spinBox_z->setValue(0);
  ui->spinBox_x_angle->setValue(0);
  ui->spinBox_y_angle->setValue(0);
  ui->spinBox_z_angle->setValue(0);
  ui->spinBox_scale->setValue(1);
  ui->spinBox_x->setEnabled(true);
  ui->spinBox_y->setEnabled(true);
  ui->spinBox_z->setEnabled(true);
  ui->spinBox_x_angle->setEnabled(true);
  ui->spinBox_y_angle->setEnabled(true);
  ui->spinBox_z_angle->setEnabled(true);
  ui->spinBox_line_width->setEnabled(true);
  ui->spinBox_point_size->setEnabled(true);
  ui->spinBox_scale->setEnabled(true);
  ui->spinBox_color_line_r->setEnabled(true);
  ui->spinBox_color_line_g->setEnabled(true);
  ui->spinBox_color_line_b->setEnabled(true);
  ui->spinBox_color_back_r->setEnabled(true);
  ui->spinBox_color_back_g->setEnabled(true);
  ui->spinBox_color_back_b->setEnabled(true);
  ui->spinBox_color_point_r->setEnabled(true);
  ui->spinBox_color_point_g->setEnabled(true);
  ui->spinBox_color_point_b->setEnabled(true);
  ui->projection_f->setEnabled(true);
  ui->projection_p->setEnabled(true);
  ui->line_type_solid->setEnabled(true);
  ui->line_type_dotted->setEnabled(true);
  ui->display_method_circle->setEnabled(true);
  ui->display_method_none->setEnabled(true);
  ui->display_method_square->setEnabled(true);
  ui->lineEdit->setEnabled(true);
  ui->lineEdit_2->setEnabled(true);
  ui->lineEdit_3->setEnabled(true);
  ui->lineEdit_4->setEnabled(true);
  ui->lineEdit_5->setEnabled(true);
  ui->lineEdit_6->setEnabled(true);
  ui->lineEdit_7->setEnabled(true);
  ui->lineEdit_8->setEnabled(true);
  ui->lineEdit_9->setEnabled(true);
  ui->lineEdit_10->setEnabled(true);
  ui->lineEdit_11->setEnabled(true);
  ui->lineEdit_13->setEnabled(true);
  ui->lineEdit_12->setEnabled(true);
  ui->lineEdit_14->setEnabled(true);
  ui->lineEdit_15->setEnabled(true);
  ui->lineEdit_16->setEnabled(true);
  ui->lineEdit_17->setEnabled(true);
  ui->lineEdit_18->setEnabled(true);
  ui->lineEdit_19->setEnabled(true);
  ui->button_create_gif->setEnabled(true);
  ui->button_create_img->setEnabled(true);
}

void MainWindow::on_button_create_gif_clicked() {
  time = 0;
  ui->button_create_gif->setEnabled(false);
  timer = new QTimer(this);
  image = new QImage;
  gif = new QGifImage(QSize(640, 480));
  connect(timer, SIGNAL(timeout()), this, SLOT(gif_f()));
  timer->start(1000);
}

void MainWindow::gif_f() {
  time++;
  ui->lineEdit_timer->setText(QString::number(5 - time));
  *image = ui->widget->grabFramebuffer();
  gif->setDefaultDelay(100);
  gif->addFrame(*image);
  if (time == 5) {
    timer->stop();
    gifPath = NULL;
    gifPath = QFileDialog::getSaveFileName(this, NULL, NULL, "GIF (*.gif)");
    if (!gifPath.isNull()) gif->save(gifPath);
    ui->lineEdit_timer->setText("");
    ui->button_create_gif->setEnabled(true);
  }
}

void MainWindow::on_button_create_img_clicked() {
  ui->widget->grabFramebuffer().save(QFileDialog::getSaveFileName(
      this, NULL, NULL, "BMP(*.bmp);; JPEG(*.jpg *.jpeg)"));
}

MainWindow::~MainWindow() { delete ui; }
