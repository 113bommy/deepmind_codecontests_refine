
def main():
    n_polyhedrons = int(input())
    total_faces = 0
    faces = {'cube':4, 'tetrahedron':6, 'octahedron':8,\
        'dodecahedron':12, 'icosahedron':20}
    for i in range(n_polyhedrons):
        total_faces += faces[input().lower()]
    print (total_faces)

main()