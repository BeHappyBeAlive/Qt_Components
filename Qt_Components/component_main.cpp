#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QPixmap>

int main(int argc, char* argv[]) {
  //��ʼ��rcc��Դ�ļ�������ָ����.qrc�ļ�
  Q_INIT_RESOURCE(resource);
  QApplication a(argc, argv);

  // ���������ڣ����� QApplication ��Ϊ������
  QWidget widget;  // ����ʹ�� QWidget widget; ��ջ�ϴ���

  // ������ǩ������ͼƬ�����ø�����Ϊ widget
  QLabel* label = new QLabel(&widget);  // ���ø�����Ϊ widget
  label->setPixmap(QPixmap(":/images/demo_rcc/logo_rcc"));

  // ����ˮƽ���ֲ�����ǩ��ӵ�������
  QHBoxLayout* h_layout = new QHBoxLayout(&widget);  // ���ø�����Ϊ widget
  h_layout->addWidget(label);

  // ���ò��ֵ�������
  widget.setLayout(h_layout);

  // ��ʾ������
  widget.show();

  // �����¼�ѭ��
  return a.exec();
}