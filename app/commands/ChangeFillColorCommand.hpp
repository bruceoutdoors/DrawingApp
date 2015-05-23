#include "Command.hpp"

#include <vector>
#include <QColor>

class Selection;

class ChangeFillColorCommand : public Command
{
public:
    ChangeFillColorCommand();
    ~ChangeFillColorCommand();

    void setColor(QColor color);

    void execute() override;
    void undo() override;

private:
    Selection *m_currentSelection;
    std::vector<QColor> m_savedColors;
    QColor m_color;
};

