#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

#include "MyGraph.h"

using namespace std;

int wait_enter_key()
{
    cerr << "hit ENTER key to continue ..." << endl;
    int ch __attribute__((unused)) = getchar();

    return 0;
}

int main(int argc, char *argv[])
{
    TApplication theApp("MyGraph", &argc, argv);

    TCanvas *c1 = new TCanvas("c1", "C1",
                    0 /*top left x*/, 0 /*top left y*/, 800 /*width*/, 600 /*height*/);

    MyGraph *g0 = new MyGraph();
    MyGraph *g1 = new MyGraph();
    g0->init(4096 /*number of x*/, 4096 /*number of y*/);
    g1->init(4096 /*number of x*/, 4096 /*number of y*/);

    g0->set_title(Form("Channel %d", 0)); /* Form(): printf style % format descriptor */
    for (int i = 0; i < 5; ++i) {
        g0->fill(i, i*i);
    }
    g0->set_min_max(0, 100); /*graph y range */

    g0->set_title(Form("Channel %d", 1));
    for (int i = 0; i < 5; ++i) {
        g1->fill(i, 2*i*i);
    }
    g1->set_min_max(0, 100);

    c1->Divide(2, 2); /* split the canvas 2 by 2 */
    c1->cd(1);        /* move to the 1st area (1-origin) */
    g0->draw();
    c1->cd(2);
    g1->draw();
    c1->Update();     /* Update the canvas */

    wait_enter_key();

    g0->reset(); /* reset g0 data */
    g1->reset(); /* reset g1 data */

    for (int i = 0; i < 5; ++i) {
        g0->fill(i, 3*i*i);
    }
    for (int i = 0; i < 5; ++i) {
        g1->fill(i, 4*i*i);
    }
    c1->cd(1);
    g0->draw();
    c1->cd(2);
    g1->draw();
    c1->Update();

    wait_enter_key();

    delete g0;
    delete g1;
    delete c1;

    return 0;
}
