#ifndef REMOVELINEBREAKWIDGET_H
#define REMOVELINEBREAKWIDGET_H

#include <QWidget>

class QLabel;
class QTextEdit;
class QVBoxLayout;

class RemoveLineBreakWidget : public QWidget {

  Q_OBJECT

 public:

  RemoveLineBreakWidget(QWidget *parent = 0);
  ~RemoveLineBreakWidget();

 private:

  QTextEdit *inputArea;
  QTextEdit *outputArea;
  QLabel *lblInput;
  QLabel *lblOutput;
  QVBoxLayout *layout;

  void removeLineBreaks(QString& str);
  void process();
  void changeEvent(QEvent* event);

};

#endif // REMOVELINEBREAK_H
