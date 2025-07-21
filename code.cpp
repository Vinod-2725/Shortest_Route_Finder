#include<bits/stdc++.h>

using namespace std;

class RailwayPlanner
{
private:
    class Vertex
    {
    public:
        unordered_map<string, int> nbrs;
    };

    unordered_map<string, Vertex> vtces;

public:
    void addStation(const string &stationName)
    {
        vtces[stationName] = Vertex();
    }

    void addConnection(const string &station1, const string &station2, int distance)
    {
        vtces[station1].nbrs[station2] = distance;
        vtces[station2].nbrs[station1] = distance;
    }

    void displayMap()
    {
        for (const auto &vtx : vtces)
        {
            cout << "Connections from " << vtx.first << ":" << endl;

            for (const auto &pair : vtx.second.nbrs)
            {
                cout << "\t" << pair.first << " - " << pair.second << "km" << endl;
            }

            cout << endl;
        }
    }

    class HeapNode
    {
    public:
        string stationName;
        int cost;
        string path;

        HeapNode(const string &name, int c, const string &p)
        {
            stationName = name;
            cost = c;
            path = p;
        }
    };

    class HeapComparator
    {
    public:
        bool operator()(const HeapNode &node1, const HeapNode &node2)
        {
            return node1.cost > node2.cost;
        }
    };

    void findShortestPath(const string &startStation, const string &endStation)
    {
        unordered_map<string, string> prevStation;
        unordered_map<string, int> distance;
        priority_queue<HeapNode, vector<HeapNode>, HeapComparator> pq;

        for (const auto &pair : vtces)
        {
            distance[pair.first] = INT_MAX;
        }

        distance[startStation] = 0;
        pq.push(HeapNode(startStation, 0, ""));

        while (!pq.empty())
        {
            HeapNode current = pq.top();
            pq.pop();

            if (prevStation.find(current.stationName) != prevStation.end())
            {
                continue;
            }

            prevStation[current.stationName] = current.path;

            const Vertex &station = vtces[current.stationName];
            for (const auto &pair : station.nbrs)
            {
                string nextStation = pair.first;
                int distanceToNextStation = pair.second;

                if (distance[nextStation] > distance[current.stationName] + distanceToNextStation)
                {
                    distance[nextStation] = distance[current.stationName] + distanceToNextStation;
                    pq.push(HeapNode(nextStation, distance[nextStation], current.path + " -> " + nextStation));
                }
            }
        }

        if (prevStation.find(endStation) == prevStation.end())
        {
            cout << "No path found from " << startStation << " to " << endStation << endl;
        }
        else
        {
            cout << "Shortest path from " << startStation << " to " << endStation << ":" << endl;
            cout << prevStation[endStation] << endl;
            cout << "Shortest distance: " << distance[endStation] << "km" << endl;
        }
    }
};

int main()
{
    RailwayPlanner Railway;
    char choice;

    int option;
    string Start,End;

    // Add stations
    Railway.addStation("Hyderabad");
    Railway.addStation("Kazipet");
    Railway.addStation("Warangal");
    Railway.addStation("Khammam");
    Railway.addStation("Madira");
    Railway.addStation("Vijayawada");
    Railway.addStation("Eluru");
    Railway.addStation("Tadepalligudem");
    Railway.addStation("Rajahmundry");
    Railway.addStation("Samalkota");
    Railway.addStation("Annavaram");
    Railway.addStation("Tuni");
    Railway.addStation("Anakapally");
    Railway.addStation("Vizag");
    Railway.addStation("Vizianagaram");
    Railway.addStation("Bhubaneswar");
    Railway.addStation("Cuttack");
    Railway.addStation("Bhadrakh");
    Railway.addStation("Balasore");
    Railway.addStation("Kharagpur");
    Railway.addStation("Howrah");
    Railway.addStation("Nalgonda");
    Railway.addStation("Miryalaguda");
    Railway.addStation("Piduguralla");
    Railway.addStation("Guntur");
    Railway.addStation("Tenali");
    Railway.addStation("Ongole");
    Railway.addStation("Nellore");
    Railway.addStation("Gudur");
    Railway.addStation("Renigunda");
    Railway.addStation("Tirupati");
    Railway.addStation("Puttur");
    Railway.addStation("Nagari");
    Railway.addStation("Tiruttani");
    Railway.addStation("Tiruvallur");
    Railway.addStation("Avadi");
    Railway.addStation("Chennai");
    Railway.addStation("Katpadi");
    Railway.addStation("Jolarpttai");
    Railway.addStation("Bengaluru");
    Railway.addStation("Guntakal");
    Railway.addStation("Raichur");
    Railway.addStation("Nagpur");
    Railway.addStation("Itarsi");
    Railway.addStation("Bhopal");
    Railway.addStation("Lakshmi Bhai Jhansi");
    Railway.addStation("Gwalior");
    Railway.addStation("Agra");
    Railway.addStation("Delhi");

    // Add connections
    Railway.addConnection("Hyderabad", "Kazipet", 135);
    Railway.addConnection("Kazipet", "Warangal", 10);
    Railway.addConnection("Warangal", "Khammam", 108);
    Railway.addConnection("Khammam", "Madira", 45);
    Railway.addConnection("Madira", "Vijayawada", 54);
    Railway.addConnection("Vijayawada", "Eluru", 69);
    Railway.addConnection("Eluru", "Tadepalligudem", 48);
    Railway.addConnection("Tadepalligudem", "Rajahmundry", 42);
    Railway.addConnection("Rajahmundry", "Samalkota", 50);
    Railway.addConnection("Samalkota", "Annavaram", 47);
    Railway.addConnection("Annavaram", "Tuni", 16);
    Railway.addConnection("Tuni", "Anakapally", 64);
    Railway.addConnection("Anakapally", "Vizag", 43);
    Railway.addConnection("Vizag", "Vizianagaram", 61);
    Railway.addConnection("Vizianagaram", "Bhubaneswar", 383);
    Railway.addConnection("Bhubaneswar", "Cuttack", 28);
    Railway.addConnection("Cuttack", "Bhadrakh", 106);
    Railway.addConnection("Bhadrakh", "Balasore", 72);
    Railway.addConnection("Balasore", "Kharagpur", 116);
    Railway.addConnection("Kharagpur", "Howrah", 120);
    Railway.addConnection("Hyderabad", "Nalgonda", 110);
    Railway.addConnection("Nalgonda", "Miryalaguda", 48);
    Railway.addConnection("Miryalaguda", "Piduguralla", 60);
    Railway.addConnection("Piduguralla", "Guntur", 76);
    Railway.addConnection("Guntur", "Tenali", 25);
    Railway.addConnection("Tenali", "Vijayawada", 32);
    Railway.addConnection("Vijayawada", "Guntur", 40);
    Railway.addConnection("Guntur", "Tenali", 25);
    Railway.addConnection("Tenali", "Ongole", 107);
    Railway.addConnection("Ongole", "Nellore", 116);
    Railway.addConnection("Nellore", "Gudur", 39);
    Railway.addConnection("Gudur", "Renigunda", 83);
    Railway.addConnection("Renigunda", "Tirupati", 10);
    Railway.addConnection("Tirupati", "Renigunda", 10);
    Railway.addConnection("Renigunda", "Puttur", 22);
    Railway.addConnection("Puttur", "Nagari", 15);
    Railway.addConnection("Nagari", "Tiruttani", 15);
    Railway.addConnection("Tiruttani", "Tiruvallur", 51);
    Railway.addConnection("Tiruvallur", "Avadi", 21);
    Railway.addConnection("Avadi", "Chennai", 21);
    Railway.addConnection("Chennai", "Katpadi", 129);
    Railway.addConnection("Katpadi", "Jolarpttai", 85);
    Railway.addConnection("Jolarpttai", "Bengaluru", 135);
    Railway.addConnection("Bengaluru", "Guntakal", 294);
    Railway.addConnection("Guntakal", "Hyderabad", 412);
    Railway.addConnection("Hyderabad", "Kazipet", 135);
    Railway.addConnection("Kazipet", "Nagpur", 444);
    Railway.addConnection("Nagpur", "Itarsi", 300);
    Railway.addConnection("Itarsi", "Bhopal", 96);
    Railway.addConnection("Bhopal", "Lakshmi Bhai Jhansi", 293);
    Railway.addConnection("Lakshmi Bhai Jhansi", "Gwalior", 98);
    Railway.addConnection("Gwalior", "Agra",128);
    Railway.addConnection("Agra", "Delhi", 188);


    do
    {
        cout<<"__Welcome to Rail Yatra__"<<endl<<endl;
        cout<<"1.Enter the source and destination stations"<<endl;
        cout<<"2.Display Map"<<endl;

        cout<<"Enter the option chosen: ";
        cin>>option;

        switch(option)
        {
            case 1:
                cout<<"Enter the Source station: ";
                cin>>Start;

                cout<<"Enter the Destination station: ";
                cin>>End;

                cout << "----------------------" << endl;
                Railway.findShortestPath(Start,End);
                cout << "----------------------" << endl;
                break;
            case 2:
                cout << "----------------------" << endl;
                Railway.displayMap();
                cout << "----------------------" << endl;
                break;
        }
        cout<<"Do you want to continue if yes press(Y) or press (N): ";
        cin>>choice;
        cout << "----------------------" << endl;
        if(choice=='N')
        {
                cout << "----------------------" << endl;
                cout<<"Thank you...!!!"<<endl;
                cout<<"Visit again..."<<endl;
                cout << "----------------------" << endl;
                break;
        }
    }while(choice=='Y'||choice=='y');

    return 0;
}