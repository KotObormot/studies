# В Qt6 метод QPainter::drawRoundRect() был окончательно удален, так как он считался устаревшим еще в Qt 5\.

Вместо него нужно использовать метод **painter.drawRoundedRect()**.

## **Особенности синтаксиса в Qt6**

В отличие от старого метода, где радиусы скругления задавались в процентах, новый метод принимает радиусы в **пикселях** (по умолчанию).

Вот точная замена для вашего кода:

*`// Qt6: сигнатура (x, y, w, h, xRadius, yRadius)`*  
`painter.drawRoundedRect(20, 120, 80, 50, 10, 10);`

## **Главные отличия:**

> * **Параметры радиуса**: Последние два числа (10, 10\) задают радиус скругления по осям X и Y в пикселях.  
> * **Режим работы**: Если вам всё же нужны проценты вместо пикселей, добавьте флаг `Qt::RelativeSize` в качестве седьмого аргумента.

Чтобы сделать ваш код еще чище, вы можете передавать в метод объект QRect или QRectF. 

Варианты замены

**С помощью объекта QRect:**  
  
    QRect rect(20, 120, 80, 50);

    painter.drawRoundedRect(rect, 10.0, 10.0); // 10.0 — радиус скругления по x и y

**Напрямую с координатами (x, y, ширина, высота):**  
  
    painter.drawRoundedRect(20, 120, 80, 50, 10.0, 10.0);

**Полезные параметры**

* Последние два аргумента задают радиус скругления в пикселях (или процентах, если использовать Qt::RelativeSize).

Для плавных и красивых углов без «лесенок» не забудьте включить сглаживание:  
 
    painter.setRenderHint(QPainter::Antialiasing, true);

---

-  [AI](https://www.google.com/search?q=%D0%BA%D0%B0%D0%BA+%D0%BF%D0%B5%D1%80%D0%B5%D0%BF%D0%B8%D1%81%D0%B0%D1%82%D1%8C+%D0%BA%D0%BE%D0%B4%2C+%D1%87%D1%82%D0%BE%D0%B1%D1%8B+%D0%B2+%D0%BD%D0%B0%D1%80%D0%B8%D1%81%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D0%BE%D0%BC+%D0%BF%D1%80%D1%8F%D0%BC%D0%BE%D0%B3%D1%83%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B5+%D0%B1%D1%8B%D0%BB+%D1%83%D0%B7%D0%BE%D1%80+%D0%BD%D0%B0+%D1%84%D0%BE%D0%BD%D0%B5+%D0%B1%D0%B5%D0%BB%D0%BE%D0%B3%D0%BE+%D1%86%D0%B2%D0%B5%D1%82%D0%B0%3A++painter.setBrush%28Qt%3A%3AHorPattern%29%3B%0D%0A++++painter.setBrush%28QBrush%28%22%23ffffff%22%29%29%3B++++%2F%2F+white%0D%0A++++painter.drawRect%2810%2C+15%2C+90%2C+60%29%3B&sca_esv=b59435e14644ce34&sxsrf=APpeQnvV6CfGhkMzjZPFz-2XRTXIY5eyUA%3A1785865732007&source=hp&ei=AyZyarGZO4qgwPAP2N-nsQc&iflsig=ABILxe8AAAAAanI0FGvbuUviatePs5DMc9MrZHHmATSN&aep=22&ved=0ahUKEwjxpsikxIeWAxUKEBAIHdjvKXYQteYPCB0&cs=1&oq=%D0%BA%D0%B0%D0%BA+%D0%BF%D0%B5%D1%80%D0%B5%D0%BF%D0%B8%D1%81%D0%B0%D1%82%D1%8C+%D0%BA%D0%BE%D0%B4%2C+%D1%87%D1%82%D0%BE%D0%B1%D1%8B+%D0%B2+%D0%BD%D0%B0%D1%80%D0%B8%D1%81%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D0%BE%D0%BC+%D0%BF%D1%80%D1%8F%D0%BC%D0%BE%D0%B3%D1%83%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B5+%D0%B1%D1%8B%D0%BB+%D1%83%D0%B7%D0%BE%D1%80+%D0%BD%D0%B0+%D1%84%D0%BE%D0%BD%D0%B5+%D0%B1%D0%B5%D0%BB%D0%BE%D0%B3%D0%BE+%D1%86%D0%B2%D0%B5%D1%82%D0%B0%3A++painter.setBrush%28Qt%3A%3AHorPattern%29%3B%0D%0A++++painter.setBrush%28QBrush%28%22%23ffffff%22%29%29%3B++++%2F%2F+white%0D%0A++++painter.drawRect%2810%2C+15%2C+90%2C+60%29%3B&gs_lp=Egdnd3Mtd2l6IpoC0LrQsNC6INC_0LXRgNC10L_QuNGB0LDRgtGMINC60L7QtCwg0YfRgtC-0LHRiyDQsiDQvdCw0YDQuNGB0L7QstCw0L3QvdC-0Lwg0L_RgNGP0LzQvtCz0YPQu9GM0L3QuNC60LUg0LHRi9C7INGD0LfQvtGAINC90LAg0YTQvtC90LUg0LHQtdC70L7Qs9C-INGG0LLQtdGC0LA6ICBwYWludGVyLnNldEJydXNoKFF0OjpIb3JQYXR0ZXJuKTsKICAgIHBhaW50ZXIuc2V0QnJ1c2goUUJydXNoKCIjZmZmZmZmIikpOyAgICAvLyB3aGl0ZQogICAgcGFpbnRlci5kcmF3UmVjdCgxMCwgMTUsIDkwLCA2MCk7SIaEBVDQDljf-ARwAngAkAEAmAGCAqAB14EBqgEHMC41Mi4zM7gBAcgBAPgBAfgBApgCP6AC_GGoAgrCAhAQIxjwBRieBhiiBxjqAhgnwgIHECMY6gIYJ8ICFhAjGO0FGPoFGIIGGIMGGN0FGOoCGCfCAhAQIxiiBxieBhjwBRjqAhgnwgIIEAAYgAQYsQPCAg4QLhiABBiKBRixAxiDAcICCxAAGIAEGLEDGIMBwgILEC4YgAQYsQMYgwHCAgQQIxgnwgINECMY8AUYngYYogcYJ8ICDRAjGKIHGJ4GGPAFGCfCAg4QABiABBiKBRixAxiDAcICCxAAGIAEGIoFGLEDwgIFEAAYgATCAgwQABiABBgKGAsYsQPCAgkQABiABBgKGAvCAgYQABgWGB7CAgUQABjvBcICCBAAGIkFGKIEwgIIEAAYFhgeGArCAgUQIRigAcICBxAhGAoYoAHCAgQQIRgVmAMI8QVRGziAaSNnnZIHBzIuMjguMzOgB9HUA7IHBzAuMjguMzO4B_FhwgcMMy4yMC4yMy4xNi4xyAeoAoAIAQ&sclient=gws-wiz&mstk=AUtExfA9YsD_lDrp422YOgtSocVJbZAcUG6_QNYxWBqEK6DZdJyO9MDC63EVzlu-Lz1rHEpOrXNJ8GYbTjc97zdmMPlobbk6XFQU1dBEj0OeqId10Lvh6RzficJQ6dMykJ1opw7_tTFF_O5XbeJYK5yPlvn_NdCMxUBerig&csuir=1&atvm=2&mtid=Ry9yaofrAo_si-gPptPA-Q0&udm=50)
- [AI](https://share.google/aimode/o016m0fS8TUuioy47)


# ẞ
