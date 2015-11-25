# convex-hull


######point-set-generator:
      creates a set of random points and outputs to stdout
          usage:
                  point-set-generator [number of points desired] [output range]
            
######brute-force:
      takes set of points from stdin and outputs a set of lines (edges of the convex-hull) -- uses the      
      brute-force algorithm.
          usage:
                  brute-force < [input file]
      
######quick-hull:
      takes set of points from stdin and outputs a set of lines (edges of the convex-hull) -- uses the      
      quickhull algorithm.
          usage:
                  quick-hull < [input file]
                  
######grapher:
      takes result of a convex-hull calculator from stdin and plots them on a cartesian 
      graph
            usage: grapher [range/size of graph]
            
####Usage Example:
      ~/convex-hull-project/src$ ./point-set-generator 20 20 | ./brute-force | ./grapher 25
      

                                                  +
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +                                 X                 (17, 18)
                                                  +
                                                  +                               0                   (16, 16)
            X                                     +                   0                               (-19, 15) (10, 15)
                                      0           +                                                   (-6, 14)
              0   0                               + 0                                                 (-18, 13) (-16, 13) (1, 13)
                                                  +                   0                               (10, 12)
                                                  +     0                                             (3, 11)
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +
                                                0 +                                                   (-1, 5)
                                                  + 0                                                 (1, 4)
                                                  +
                                0                 +                                                   (-9, 2)
                                                  +
+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +
                                                  +
                                0                 +                                                   (-9, -2)
                                                  +
                          0                       +                                                   (-12, -4)
                                                  +
                    X                             +                                                   (-15, -6)
                                                  +
                                                  +
                                0                 +                                                   (-9, -9)
                                                  +
                                                  +
                                                  +
                                                  +                                 X                 (17, -13)
                                                  +
                                                  +
                                                  +
                                                  +                         X                         (13, -17)
                                                  +   X                                               (2, -18)
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +
                                                  +

