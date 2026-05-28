2026-05-28 0040 Определение пути к файлу / 0040 Defining a file path

https://www.youtube.com/watch?v=ACGb_vHd3T0&list=PL0-ON4z3RPUO-BMP4L-9UvG2ADmMWhW24&index=40

427 просмотров  23 окт. 2021 г.  Qt Начало
В данном видео уроке мы с вами определим путь к исходному файлу, так же определим полное название файла + его расширение.
/ 
427 views Oct 23, 2021 Qt Start
In this video tutorial, we'll determine the path to the source file, as well as the full file name and extension.

See also https://ravesli.com/urok-5-rabota-s-fajlami-i-katalogami-v-qt5/#toc-8

Файл идентифицируется по имени и по пути. Путь состоит из имени файла, базового имени и суффикса. 
/ 
A file is identified by its name and path. The path consists of the file name, base name, and suffix.


==========================================================
Разница между методами QFileInfo::suffix() и QFileInfo::completeSuffix() заключается в том, с какой именно точки (с первого или с последнего знака точки в имени) они начинают отсчитывать расширение файла.

Ключевое отличие

suffix() возвращает расширение, идущее после последней точки в имени файла.

completeSuffix() возвращает составное расширение, начиная от первой точки в имени файла.

Примечание касательно .bashrc: для скрытых файлов Unix, имя которых начинается с точки, обе функции считают эту первую точку системным префиксом, поэтому базовым именем (baseName()) будет считаться пустая строка, а суффиксом — всё слово целиком.

Каждому методу суффикса соответствует свой метод получения имени файла без расширения:

В паре с suffix() логично использовать completeBaseName() (для archive.tar.gz вернет archive.tar).

В паре с completeSuffix() используется baseName() (для archive.tar.gz вернет archive).

В большинстве стандартных задач (когда у файла только одно расширение вроде .txt или .png) результат работы обоих методов абсолютно идентичен. 

Использовать completeSuffix() стоит только тогда, когда ваше приложение обрабатывает файлы со сложными или составными расширениями (например, .tar.gz, .tar.bz2, .page.html).

Сводная таблица для разных имен файлов

Имя файла -> Результат suffix() -> Результат completeSuffix()

photo.jpg -> "jpg" -> "jpg"

archive.tar.gz -> "gz" -> "tar.gz"

draft.v1.update.docx -> "docx" -> "v1.update.docx"

README (без точки) -> "" (пустая строка) -> "" (пустая строка)

.bashrc (Unix-файл) -> "bashrc" -> "bashrc"
