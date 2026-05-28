2026-05-28 Права доступа / Access rights

https://ravesli.com/urok-5-rabota-s-fajlami-i-katalogami-v-qt5/#toc-9

Файлы в файловой системе имеют систему защиты: флаги, которые определяют, кто может получить доступ к файлам и изменять их, а кто — нет. 
Метод QFile::permissions() возвращает перечисление флагов для рассматриваемого файла. 

Существует 3 типа возможных пользователей:

   владелец;

   группа, к которой принадлежит файл;

   все остальные пользователи, именуемые others.

Первые три позиции показывают права владельца файла, следующие три позиции — группы, в которую входит файл, а последние три символа показывают права остальных пользователей.

Существует 4 вида прав:

   чтение (r);

   запись или изменение (w);

   выполнение (x);

   отсутствие прав (-).

Примечание: pаботает только в Unix-системах.
/ 

Files in the file system have a security system: flags that determine who can access and modify them and who cannot. The QFile::permissions() method returns an enumeration of flags for the given file. The following example creates a Unix-style list of permissions for the specified file.

There are three types of possible users:

the owner;

the group to which the file belongs;

all other users, called others.

The first three characters indicate the file owner's permissions, the next three characters indicate the group to which the file belongs, and the last three characters indicate the permissions of other users.

There are four types of permissions:

read (r);

write or modify (w);

execute (x);

no permissions (-).

Note: The following example only works on Unix systems.
