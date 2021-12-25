#MATRIX ROTATION

#define loop(i,n) for(int i=0;i<n;i++)


void rotate(vector<vector<int> > &mat) {
    reverse(mat.begin(), mat.end());
    loop(i,mat.size()) for (int j = i + 1; j < mat[i].size(); ++j) swap(mat[i][j], mat[j][i]);
}


void anti_rotate(vector<vector<int> > &mat) {
    for (auto it : mat) reverse(it.begin(), it.end());
    loop(i,mat.size()) for (int j = i + 1; j < mat[i].size(); ++j) swap(mat[i][j], mat[j][i]);
}

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/


/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/