#include <QCoreApplication>
#include <QDebug>

#include <algorithm>
#include <vector>

bool isOdd (int i)
{
    return ((i%2)==1);
}

void testFind()
{
    qDebug()<<"****************//*Test Find*//****************";

    std::vector<int> data = { 1, 1, 2, 3, 3, 4, 5, 6, 5, 4, 3, 7 };

    //std::find
    qDebug() << "std::find";

    std::vector<int>::iterator result1 = std::find( data.begin(), data.end(), 3 );

    if( result1 != data.end() )
    {
        qDebug() << *result1;
        qDebug() << result1 - data.begin();
    }
    else
    {
        qDebug() << "Find NULL !";
    }

    std::vector<int>::iterator result2 = std::find( data.begin() + 5, data.end(), 3 );

    if( result2 != data.end() )
    {
        qDebug() << *result2;
        qDebug() << result2 - data.begin();
    }
    else
    {
        qDebug() << "Find NULL !";
    }

    //std::find_if
    qDebug() << "std::find_if";

    auto result3 =std::find_if( data.begin(), data.end(), isOdd );

    if( result3 != data.end() )
    {
        qDebug() << *result3;
        qDebug() << result3 - data.begin();
    }
    else
    {
        qDebug() << "Find NULL !";
    }

    //std::find_if_not
    qDebug() << "std::find_if_not";

    auto result4 =std::find_if_not( data.begin(), data.end(), [](int i)->bool{ return ((i%2)==1); } );

    if( result4 != data.end() )
    {
        qDebug() << *result4;
        qDebug() << result4 - data.begin();
    }
    else
    {
        qDebug() << "Find NULL !";
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testFind();

    return a.exec();
}
