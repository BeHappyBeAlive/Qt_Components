#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QPixmap>

int main(int argc, char* argv[]) {
  //初始化rcc资源文件，这里指的是.qrc文件
  Q_INIT_RESOURCE(resource);
  QApplication a(argc, argv);

  // 创建主窗口，设置 QApplication 作为父对象
  QWidget widget;  // 或者使用 QWidget widget; 在栈上创建

  // 创建标签并设置图片，设置父对象为 widget
  QLabel* label = new QLabel(&widget);  // 设置父对象为 widget
  label->setPixmap(QPixmap(":/images/demo_rcc/logo_rcc"));

  // 创建水平布局并将标签添加到布局中
  QHBoxLayout* h_layout = new QHBoxLayout(&widget);  // 设置父对象为 widget
  h_layout->addWidget(label);

  // 设置布局到主窗口
  widget.setLayout(h_layout);

  // 显示主窗口
  widget.show();

  // 进入事件循环
  return a.exec();
}