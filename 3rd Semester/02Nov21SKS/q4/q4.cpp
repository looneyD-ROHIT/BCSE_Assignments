#include <bits/stdc++.h>
using namespace std;

class cricketer
{
public:
    string name;
    string dob;
    int m_played;

    cricketer(string name = "NULL", string dob = "NULL", int m_played = 0)
    {
        this->name = name;
        this->dob = dob;
        this->m_played = m_played;
    }
    cricketer(const cricketer &c)
    {
        this->name = c.name;
        this->dob = c.dob;
        this->m_played = c.m_played;
    }
    void showDataCricketer()
    {
        cout << "NAME: " << this->name << endl;
        cout << "DOB: " << this->dob << endl;
        cout << "MATCHES PLAYED: " << this->m_played << endl;
    }
};

class bowler : virtual public cricketer
{
public:
    int n_wickets;
    float economy;
    bowler(const cricketer &bow, int n_wickets = 0, float economy = 0) : cricketer(bow)
    {
        this->n_wickets = n_wickets;
        this->economy = economy;
    }
    bowler(const bowler &bow) : cricketer(bow)
    {
        this->n_wickets = bow.n_wickets;
        this->economy = bow.economy;
    }
    void showDataBowler()
    {
        cout << "NO. OF WICKETS TAKEN: " << this->n_wickets << endl;
        cout << "ECONOMY: " << this->economy << endl;
    }
};

class batsman : virtual public cricketer
{
public:
    int runs;
    float average_score;
    batsman(const cricketer &bat, int runs = 0, float average_score = 0) : cricketer(bat)
    {
        this->runs = runs;
        this->average_score = average_score;
    }
    batsman(const batsman &bat) : cricketer(bat)
    {
        this->runs = bat.runs;
        this->average_score = bat.average_score;
    }
    void showDataBatsman()
    {
        cout << "RUNS: " << this->runs << endl;
        cout << "AVERAGE SCORE: " << this->average_score << endl;
    }
};
class allrounder : public bowler, public batsman
{
public:
    allrounder(const bowler &bow, const batsman &bat) : cricketer(bow), bowler(bow), batsman(bat)
    {
        cout << "\nALL-ROUNDER CONSTRUCTOR!\n"
             << endl;
    }
    void showData()
    {
        this->showDataCricketer();
        this->showDataBowler();
        this->showDataBatsman();
    }
};
class doubleWicket
{
    bowler *bow;
    batsman *bat;

public:
    doubleWicket(const bowler &bow, const batsman &bat)
    {
        this->bow = new bowler(bow);
        this->bat = new batsman(bat);
    }
    void showDataDBW()
    {
        bow->showDataCricketer();
        bow->showDataBowler();
        bat->showDataBatsman();
    }
};

int main()
{
    cricketer c("abcd", "01-01-1990", 100);
    bowler bow(c, 10, 5);
    batsman bat(c, 100, 15);

    allrounder ar(bow, bat);
    doubleWicket dbw(bow, bat);
    cout << "ALL-ROUNDER:" << endl;
    ar.showData();
    cout << "----------------------------------------------------------" << endl;
    cout << "DOUBLE-WICKET:" << endl;
    dbw.showDataDBW();
    return 0;
}