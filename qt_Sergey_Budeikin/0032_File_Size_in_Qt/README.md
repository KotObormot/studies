2026-05-22 0032 Размер файла в Qt / 0032 File size in Qt

https://www.youtube.com/watch?v=Cx4rN-MmrE4&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=32&t=5s

330 просмотров  20 окт. 2021 г.  Qt Начало
В данном видео уроке мы с вами рассмотрим один из вариантов как при помощи созданной нами программы и консоли измерить размер файла.
/ 
330 views Oct 20, 2021 Qt Start
In this video tutorial, we'll look at one way to measure file size using the program we created and the console.

See also: https://ravesli.com/urok-5-rabota-s-fajlami-i-katalogami-v-qt5/#toc-0

работу с файлами и каталогами в Qt5. Для этого мы будем использовать следующие классы:

   QFile, QDir и QFileInfo — основные классы для работы с файлами в Qt5;

   QFile — предоставляет интерфейс для чтения и записи информации в файлы;

   QDir — обеспечивает доступ к структуре каталогов и к их содержимому;

   QFileInfo — предоставляет информацию о файле, включая его имя и расположение в файловой системе, время доступа и изменения, имя владельца файла и текущие разрешения.
/ 
Working with files and directories in Qt5. For this, we'll use the following classes:

QFile, QDir, and QFileInfo — the main classes for working with files in Qt5;

QFile — provides an interface for reading and writing information to files;

QDir — provides access to the directory structure and its contents;

QFileInfo — provides information about a file, including its name and location in the file system, access and modification times, the file owner, and current permissions.

Для определения размера файла в классе QFileInfo предусмотрен метод size():
/ 
To determine the file size, the QFileInfo class provides the size() method:
