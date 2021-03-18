#pragma once
#include< iostream>
using namespace std;

class Door{
    class State* current;
public:
    Door();
    void setCurrent(State* s)
    {
        current = s;
    }
 /*   void opend()
    {
        current->opend(this);
    }
    void close()
    {
        current->close(this);
    }
    void lock()
    {
        current->lock(this);
    }
    void unlock()
    {
        current->unlock(this);
    }*/
};


class State {
public:
    virtual void opend(Door* d)
    {
        cout << "   already Opened\n";
    }
    virtual void close(Door* d)
    {
        cout << "   already Closed\n";
    }
    virtual void lock(Door* d)
    {
        cout << "   already Locked\n";
    }
    virtual void unlock(Door* d)
    {
        cout << "   hasn't Looked\n";
    }
};

class Opened : public State {
public:
    Opened()
    {
        cout << "   Opened-ctor ";
    };

    ~Opened()
    {
        cout << "   dtor-Opend\n";
    };

    /* void close(Door* d)
     {
         cout << "   going from Opened to Closed";
         d->setCurrent(new Closed());
         delete(this);
     }

     void lock(Door* d)
     {
         cout << "   please close first\n";
     }
     */
};

class Closed : public State {
public:
    Closed()
    {
        cout << "   Closed-ctor ";
    };

    ~Closed()
    {
        cout << "   dtor-Closed\n";
    };

    /*void opend(Door* d)
    {
        cout << "   going from Closed to Opened";
        d->setCurrent(new Opened());
        delete(this);
    }

    void lock(Door* d)
    {
        cout << "   going from Closed to Locked";
        d->setCurrent(new Locked());
        delete(this);
    }*/
};

class Locked : public State {
public:
    Locked()
    {
        cout << "   Locked-ctor ";
    };

    ~Locked()
    {
        cout << "   dtor-Locked\n";
    };

    /*   void opend(Door* d)
       {
           cout << "   please unlock first\n";
       }

       void unlock(Door* d)
       {
           cout << "   going from Locked to Closed";
           d->setCurrent(new Closed());
           delete(this);
       }*/
};

Door::Door() {
    current = new Opened();
    cout << "\n";
}
