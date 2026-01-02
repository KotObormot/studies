#include <iostream>
#include <memory>
#include <vector>
// Использование this
// https://www.youtube.com/watch?v=vkUlb7Udjf4

#define VARIANT true

class Widget;

std::vector<std::shared_ptr<Widget>> processedWidgets;

#if VARIANT
class Widget : public std::enable_shared_from_this<Widget> {  // curiosly reccurring template pattern (CRTP)
                                                              // странно повторяющийся шаблон
  public:
    static std::shared_ptr<Widget> create() {
        return std::shared_ptr<Widget>();
    }  

    void process() {
        processedWidgets.emplace_back(shared_from_this());
    }

  private:
    Widget() {}
};

#else
class Widget {
  public:
    void process() {
        processedWidgets.emplace_back(this);
    }
};
#endif

int main() {
#if VARIANT
    auto w = Widget::create();
#else
    auto w = std::make_shared<Widget>();
#endif
    w->process();
}

