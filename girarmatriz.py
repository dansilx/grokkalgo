class Solutions: 
    def rotate(self, matrix: List[List[int]]) -> None:
        l, r = 0, len(matrix)-1
    
        while l < r:
            for i in range(r-l):
                