# 2026-11-01 / Урок №14. Создание игры «Змейка» на C++/Qt5 / Snake in Qt5

-    [Ravesli](https://ravesli.com/urok-14-sozdaem-igru-zmejka-v-qt5/)

- [Zetcode](https://zetcode.com/gui/qt5/snake/)

- [GitHub](https://github.com/Ravesli/Qt5)

## Игра «Змейка» / Snake

Игра «Змейка» — это старая классическая видеоигра. Впервые она была создана в конце 70-х годов для использования на игровых автоматах, а затем в 1979 году её перенесли и на ПК. В этой игре игрок управляет тонким существом, похожим на змею, которое перемещается по игровому полю без остановки. Цель состоит в том, чтобы съесть как можно больше яблок, появляющихся в процессе игры. Каждый раз, когда змея съедает яблоко, она становится длиннее, что усложняет дальнейший процесс игры. Змея при этом должна избегать столкновений со стенами и собственным телом.

//

Snake is an older classic  video game. It was first created in late 70s. Later it was brought to PCs. In this game the player controls a snake. The objective is to eat as many apples as possible. Each time the snake eats an apple, its body grows. The snake must avoid the walls and its own body. This game is sometimes called Nibbles. 

### Разработка игры «Змейка» / Development

Размер каждой отдельной «части» тела змеи составляет 10 пикселей. Управляется она с клавиатуры при помощи стрелочек: `←`, `→`, `↑`, `↓`. Изначально тело змеи состоит из трех «частей». Если игра завершилась, то в центре игрового поля отображается сообщение `Game Over`.

// 

The size of each of the joints of a snake is 10 px. The snake is controlled with the cursor keys. Initially, the snake has three joints. If the game is finished, the `Game Over` message is displayed in the middle of the board. 

# ẞ
