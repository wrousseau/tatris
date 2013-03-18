#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QMainWindow>
#include <string>

extern bool isMusicOn;
extern bool areSoundsOn;
extern QString currentTheme;

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit OptionsWindow(QWidget *parent = 0);
    ~OptionsWindow();

signals:
    void goToMenuSignal();

public slots:
    void goToMenu();
    void toggleSounds(int par1);
    void toggleMusic(int par1);
    void changeTheme(QAction* action);

    
private:
    Ui::OptionsWindow *ui;
};

#endif // OPTIONSWINDOW_H
