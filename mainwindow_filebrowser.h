#ifndef MAINWINDOW_FILEBROWSER_H
#define MAINWINDOW_FILEBROWSER_H
#pragma once
#include"filestrateg.h"
#include"byfile.h"
#include"bytype.h"
#include<QString>
#include<QMap>
#include<iostream>
class MainWindow_FileBrowser //класс через который клиент взаимодействует с приложением
{

 FileStrateg* strat_type; //выбраная стратегия
 FileStrateg* file = new ByFile();
 FileStrateg* type = new ByType();
public:
    MainWindow_FileBrowser(FileStrateg* strat_type_){
         strat_type =  strat_type_;
    }

     void setPercentageStrategy(qint32 const& index); //метод для установки стратегии


      QMap<QString, QPair< uint64_t,double>>  useCalculate(QString const& path );/*метод вычисляет размер по текущей стратегии
                                                                                  принимает путь к папке из которой будет вестись подчет
                                                                                  возращает словарь где ключи имена папки, значение это пары размер в байтах и процентах*/

};

#endif // MAINWINDOW_FILEBROWSER_H
