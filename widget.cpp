#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include "widget.h"

RemoveLineBreakWidget::RemoveLineBreakWidget(QWidget *parent) : QWidget(parent) {
  
  lblInput = new QLabel("Input Text (pasted directly from clipboard)", this);
  inputArea = new QTextEdit(this);
  inputArea->setText("Insert the text you need to remove line breaks here.");
  lblOutput = new QLabel("Output Text (has sent to clipboard)", this);
  outputArea = new QTextEdit(this);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(lblInput);
  layout->addWidget(inputArea);
  layout->addWidget(lblOutput);
  layout->addWidget(outputArea);
  this->setLayout(layout);
}

RemoveLineBreakWidget::~RemoveLineBreakWidget() {
}

void RemoveLineBreakWidget::removeLineBreaks(QString& str) {
  
  str.replace("-\n ", "");
  str.replace("-\n", "");
  str.replace(" \n", " ");
  str.replace("\n ", " ");
  str.replace("\n", " ");
  // str.replace("\n", " ");
}

void RemoveLineBreakWidget::process() {
  QClipboard *clipboard = QApplication::clipboard();
  const QMimeData *mimeData = clipboard->mimeData();

  if (mimeData->hasText()) {
    // paste text from clip board to inputArea
    inputArea->clear();
    inputArea->paste();
    // remove line breaks of the inputArea text
    QString str = inputArea->toPlainText();
    removeLineBreaks(str);
    // show the converted text and copy back to clipboard
    outputArea->setText(str);
    clipboard->setText(str);
  }
}

void RemoveLineBreakWidget::changeEvent(QEvent* event) {
  QWidget::changeEvent(event);
  // when the widget gains focus, try to process the text from clipboard
  if (event->type() == QEvent::ActivationChange) {
    if(this->isActiveWindow()) {
      process();
    }
  }  
}
