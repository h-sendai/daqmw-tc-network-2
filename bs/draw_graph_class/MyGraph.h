#include <iostream>
#include <vector>

using namespace std;

#include <TApplication.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TFile.h>
#include <TH1.h>
#include <TRandom.h>
#include <TGraph.h>
#include <TMarker.h>
#include <TText.h>

class MyGraph
{
public:
	MyGraph();
	MyGraph(const MyGraph& rhs);
    MyGraph& operator =(const MyGraph& rhs);
	virtual ~MyGraph();
    int set_debug();
    int unset_debug();
    int init(unsigned int x_size, unsigned int y_size);
    int fill(unsigned int x, unsigned short y);
    int set_title(string title);
    int set_min_max(int lower_y, int upper_y);
    int draw();
    int reset();
    int dump();
private:
    bool   m_debug;
	vector <int> m_x;
	vector <unsigned short> m_y;
    // TCanvas *m_c1;
    TGraph  *m_graph;
    TText   *m_text;

};
