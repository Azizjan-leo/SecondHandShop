#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Good
{
public:
    Good()
    {
        id = NULL;
        GoodName = "";
        GivenPrice = NULL;
        ActualPrice = NULL;
    }
    Good(int id,
        string GoodName,
        double GivenPrice,
        double ActualPrice)
    {
        this->id = id;
        this->GoodName = GoodName;
        this->GivenPrice = GivenPrice;
        this->ActualPrice = ActualPrice;
    }

private:
    int id;
    string GoodName;
    double GivenPrice;
    double ActualPrice;

    friend ostream& operator<<(ostream& os, const Good& good);
    friend istream& operator>>(istream& is, Good& good);
};

ostream& operator<<(ostream& os, const Good& good)
{
    os << good.id << " " << good.GoodName << " " << good.ActualPrice << " " << good.GivenPrice;
    return os;
}
istream& operator>>(istream& is, Good& good)
{
    is >> good.id >> good.GoodName >> good.ActualPrice >> good.GivenPrice;
    return is;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string path = "file.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        string msg;
        int value;
        cout << "Файл открыт!" << endl;
        cout << "Введите 1 для записи товаров в файл." << endl;
        cout << "Введите 2 для чтения товаров из файл." << endl;
        cin >> value;

        if (value == 1)
        {
            Good good(2, "Box", 500, 250);
            fs << good << "\n";
        }

        if (value == 2)
        {
            while (true)
            {
                Good good;
                fs >> good;
                if (fs.eof())
                {
                    break;
                }
                cout << good << endl;
            }
        }
    }
    fs.close();
    system("pause");
    return 0;
}