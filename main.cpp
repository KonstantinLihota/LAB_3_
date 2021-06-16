#include"filestrateg.h"
#include"mainwindow_filebrowser.h"
#include"byfile.h"
#include"bytype.h"
#include<QString>
#include<iostream>
void print(QMap<QString, QPair< uint64_t,double>> files){ //функция печати на консоль
    QList<QString> NameFiles = files.keys();
    QList< QPair< uint64_t,double>> SizeFile = files.values();
    for (int i=0; i<files.size(); i++ ){
     if (files.values()[i].second<0.01){
          std::cout<<NameFiles[i].toStdString()<<' '<< files.values()[i].first <<" <0.01" <<std::endl;
     }
else{
    std::cout.precision(2);
    std::cout<<NameFiles[i].toStdString()<<' '<< files.values()[i].first <<' ' << files.values()[i].second<<std::endl;
}
    }

}
/*
паттерн стратегия
Стратегия — это поведенческий паттерн, который определяет семейство схожих алгоритмов
 и помещает каждый из них в собственный класс,
 после чего алгоритмы можно взаимозаменять прямо во время исполнения программы.

 Вместо того, чтобы изначальный класс сам выполнял тот или иной алгоритм,
он будет играть роль контекста, ссылаясь на одну из стратегий и делегируя ей выполнение работы.
*/
int main()
{ MainWindow_FileBrowser* client = new MainWindow_FileBrowser(new ByFile());
  QString path = "C:\\Program Files\\Git"; //путь к папке
  QMap<QString, QPair< uint64_t,double>> files;

  client->setPercentageStrategy(0); //изменяем стратегию
  files = client->useCalculate(path);
  print(files);





}
