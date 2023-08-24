int largestRectangleArea(vector<int>& arr) {
    vector<int>res;
    vector<int>res1;
    int n=arr.size();
    stack<int>st;
    for(int i=n-1;i>=0;i--)
    {
      int c=1;
      if (st.empty()) {
        st.push(i);
        res.push_back(1);
      }
      else
      {
        if (arr[i] > arr[st.top()]) {
          res.push_back(1);
          st.push(i);
        } else {
          while (!st.empty()) {
            if (arr[st.top()] >= arr[i])
              {
                  c++;
                  st.pop();
              }
            else {
              res.push_back((st.top()-i));
              st.push(i);
              break;
            }
          }
          if (st.empty()) {
            st.push(i);
            res.push_back((n-i));
          }
        }
      }
      
    }
    while(!st.empty())
    st.pop();
    for(int i=0;i<n;i++)
    {
      int c=1;
      if (st.empty()) {
        st.push(i);
        res1.push_back(0);
      }
      else
      {
        if (arr[i] > arr[st.top()]) {
          res1.push_back(0);
          st.push(i);
        } else {
          while (!st.empty()) {
            if (arr[st.top()] >= arr[i])
              {
                  c++;
                  st.pop();
              }
            else {
              res1.push_back((i-st.top())-1);
              st.push(i);
              break;
            }
          }
          if (st.empty()) {
            st.push(i);
            res1.push_back((i));
          }
        }
      }
      
    }
    reverse(res.begin(),res.end());
   

    for(int i=0;i<n;i++)
    res[i]=res[i]+res1[i];
     
    for(int i=0;i<n;i++)
    res[i]=arr[i]*res[i];
   
    return *max_element(res.begin(), res.end());;
    }
