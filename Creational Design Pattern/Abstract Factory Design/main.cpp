#include <iostream>
using namespace std;

class IButton
{
public:
    virtual void press() = 0;
};

class MacButton : public IButton
{
public:
    void press()
    {
        cout << "Mac Button Pressed" << endl;
    }
};

class WinButton : public IButton
{
public:
    void press()
    {
        cout << "Win Button Pressed" << endl;
    }
};

class ITextBox
{
public:
    virtual void showText() = 0;
};

class MacTextBox : public ITextBox
{
public:
    void showText()
    {
        cout << "Showing Mac TextBox" << endl;
    }
};

class WinTextBox : public ITextBox
{
public:
    void showText()
    {
        cout << "Showing Win TextBox" << endl;
    }
};

class IFactory
{
public:
    virtual IButton *CreateButton() = 0;
    virtual ITextBox *CreateTextBox() = 0;
};

class MacFactory : public IFactory
{
public:
    IButton *CreateButton()
    {
        return new MacButton();
    }
    ITextBox *CreateTextBox()
    {
        return new MacTextBox();
    }
};

class WinFactory : public IFactory
{
public:
    IButton *CreateButton()
    {
        return new WinButton();
    }
    ITextBox *CreateTextBox()
    {
        return new WinTextBox();
    }
};

class GUIAbstractFactory
{
public:
    static IFactory *CreateFactory(string osType)
    {
        if (osType == "windows")
            return new WinFactory();
        else if (osType == "mac")
            return new MacFactory();
        else
            return new WinFactory();
    }
};

main()
{
    cout << "Enter your machine OS" << endl;
    string osType;
    cin >> osType;

    IFactory *fact = GUIAbstractFactory::CreateFactory(osType);

    IButton *button = fact->CreateButton();
    button->press();

    ITextBox *textBox = fact->CreateTextBox();
    textBox->showText();
    return 0;
}