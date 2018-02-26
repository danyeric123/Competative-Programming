
struct PolyInsideTest
{
      struct Point{
            int x,y;
      };

      vector< Point > Polygon;

      void addVertex(int x,int y) // Should be in Clockwise!.
      {
            Point p;
            p.x = x;
            p.y = y;
            Polygon.pb(p);
      }

      void MakeItClockwise() // Call this if input is given in Anticlockwise!.
      {
            reverse(Polygon.begin(),Polygon.end());
      }

      void PrintPolygon(){
            for(int i=0;i<Polygon.size();i++){
                  cout << Polygon[i].x << "," << Polygon[i].y << endl;
            }
      }

      bool isInside(int x,int y){
		int c = 0;
		int n = Polygon.size();
		if(n<=2)
                  return false;

		int i=0,j;
		do {
                  j = (i+n-1)%n;
                  int x1 = Polygon[i].x,y1 = Polygon[i].y;
                  int x2 = Polygon[j].x,y2 = Polygon[j].y;

			if (y1 == y){     // Same yLine of a Point1
                        if(x1 == x) // Same Point1 as Polygon (On Polygon Case)
                              return true;
                        if(y2 == y){ // Same yLine of both Points
                              if(x2 == x) //Same Point2 in Polygon (On Polygon Case)
                                    return true;
                              if(x2<x && x1>x) // Same yLine inside x region
                                    return true;
                              if(x1<x && x2>x) // Same yLine inside x region
                                    return true;
                        }
			}

			if((y1  > y) != (y2 > y))  // Inside y region
                  {
				int DotProduct =  (x1 - x) * (y2 - y) - (x2 - x) * (y1 - y);
				if (DotProduct == 0)
					return true;
				if ((DotProduct > 0) != (y2 - y1 > 0))
					c++;
			}

			i=j;
		}while(i!=0);
		return c&1;
	}

};
