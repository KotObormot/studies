2026-05-31 0044 Кнопка / 0044 Button

https://www.youtube.com/watch?v=VSa08RvahTw&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=44

302 просмотра  24 окт. 2021 г.  Qt Начало
В данном видео уроке мы рассмотрим вариант как можно создать кнопку которая выполняет простое действие. / 302 views Oct 24, 2021 Qt Start
In this video tutorial, we'll look at how to create a button that performs a simple action.

============================================================

See also https://ravesli.com/urok-6-osnovy-raboty-s-gui-v-qt5/#toc-4

В следующем примере мы добавим на нашу форму самую обычную кнопку. Нажатие на кнопку приведет к закрытию приложения. И здесь же впервые будут использованы понятия сигналов и слотов. При нажатии на кнопку, генерируется сигнал clicked. Слот — это метод, который реагирует на сигнал. В нашем случае это будет слот quit основного объекта приложения. QApp — это глобальный указатель на объект приложения. Он определен в заголовочном файле QApplication. / In the following example, we'll add a simple button to our form. Clicking the button will close the application. This is also where the concepts of signals and slots are first used. When the button is clicked, the "clicked" signal is generated. A slot is a method that responds to the signal. In our case, this will be the "quit" slot of the main application object. QApp is a global pointer to the application object. It is defined in the QApplication header file.

