cmake_minimum_required(VERSION 3.15)
project(HoangVu)

set(CMAKE_CXX_STANDARD 14)

add_executable(HoangVu
        Bedao/id04/nand.cpp
        Bedao/id04/REFI.cpp
        Bedao/id04/SUDI.cpp
        Bedao/id04/ZEZE.cpp
        "Data Structure/BinaryIndexTree/BIT.cpp"
        "Data Structure/BinaryIndexTree/BIT2D.cpp"
        "Data Structure/BinaryIndexTree/NTSEQ.cpp"
        "Data Structure/BinaryIndexTree/test.cpp"
        "Data Structure/Convex Hull/convexhull.cpp"
        "Data Structure/DSU/dsu.cpp"
        "Data Structure/DSU/dsurmq.cpp"
        "Data Structure/DSU/DynamicConnectivity.cpp"
        "Data Structure/DSU/qbmst.cpp"
        "Data Structure/Heap/buildheap.cpp"
        "Data Structure/Heap/heap.cpp"
        "Data Structure/Heap/protect.cpp"
        "Data Structure/LazyPropagation/QMAX.cpp"
        "Data Structure/segmenttree/Area.cpp"
        "Data Structure/segmenttree/countdfr.cpp"
        "Data Structure/segmenttree/gss.cpp"
        "Data Structure/segmenttree/r-aveseq.cpp"
        "Data Structure/segmenttree/segmentmax.cpp"
        "Data Structure/segmenttree/segmentodd.cpp"
        "Data Structure/segmenttree/segmentsum.cpp"
        "Data Structure/Skip List/skiplist.cpp"
        "Data Structure/Sparse Table/qmax.cpp"
        "Data Structure/SplayTree/SplayTree.cpp"
        "Data Structure/SqrtDecomposition/maxqueries.cpp"
        "Data Structure/Trie/sec.cpp"
        "Data Structure/Trie/Trie.cpp"
        DivideandConquer/marka.cpp
        DivideandConquer/nearest.cpp
        "Dynamic Programming/Bitmask/assignwork.cpp"
        "Dynamic Programming/Bitmask/floorboards.cpp"
        "Dynamic Programming/Bitmask/minhamilton.cpp"
        "Dynamic Programming/Digit/demso.cpp"
        "Dynamic Programming/Digit/Digitappearktimes.cpp"
        "Dynamic Programming/Digit/DPD1.cpp"
        "Dynamic Programming/splitnumber.cpp"
        Graph/BFS/BFS.cpp
        Graph/BFS/otomat.cpp
        Graph/CutandBrigde/graph_.cpp
        Graph/cycleinGraph/cycle.cpp
        Graph/DAG/LongestPath/longeststringchain.cpp
        Graph/DFS/DFS.cpp
        Graph/Dijkstra/binladen.cpp
        Graph/Dijkstra/dhfrbus.cpp
        Graph/Dijkstra/dijkstra.cpp
        Graph/Dijkstra/mele3.cpp
        Graph/Dijkstra/qbschool.cpp
        Graph/Dijkstra/roads.cpp
        Graph/Floyd/floyd.cpp
        Graph/Floyd/roads-lad.cpp
        Graph/Floyd/shortestcycle.cpp
        Graph/LongestPath/LongPath.cpp
        Graph/MinSpanningTree/FastPrim.cpp
        Graph/MinSpanningTree/Kruskal.cpp
        Graph/MinSpanningTree/PrimHeap.cpp
        Graph/StronglyConnected/Tarjan.cpp
        Graph/Trees/balance.cpp
        Graph/Trees/fselect.cpp
        Graph/Trees/haha.cpp
        Graph/Trees/lca.cpp
        Graph/Trees/lcaoffline.cpp
        Graph/Trees/lubenica.cpp
        Graph/Trees/makeprime.cpp
        Graph/Trees/MaxPath.cpp
        Graph/Trees/ptree.cpp
        Graph/Trees/pwalk.cpp
        "Greedy Algo/flowers.cpp"
        "Khu ma tran/fibonacci.cpp"
        NumberTheory/mobiusfunction.cpp
        PointandCircle/ptcc.cpp
        Recursion/Memoization/HanoiTower.cpp
        Spoj/ADBRACK.cpp
        Spoj/ADS.cpp
        Spoj/ALADDIN.cpp
        Spoj/AMSSEQ.cpp
        Spoj/BASEH.cpp
        Spoj/BESTSPOT.cpp
        Spoj/BIGNUM.cpp
        Spoj/BINARY.cpp
        Spoj/BINARY2.cpp
        Spoj/BINLADEN.cpp
        Spoj/BLOPER.cpp
        Spoj/BONUS.cpp
        Spoj/C11CAVE.cpp
        Spoj/C11SEQ.cpp
        Spoj/C11STR2.cpp
        Spoj/C11WATER.cpp
        Spoj/CHESSCBG.cpp
        Spoj/COUNTCBG.cpp
        Spoj/COUNTPL.cpp
        Spoj/COWGIRL.cpp
        Spoj/CPPSET.cpp
        Spoj/CRATE.cpp
        Spoj/CREC01.cpp
        Spoj/CRITICAL.cpp
        Spoj/CTNOWN.cpp
        Spoj/CWAY.cpp
        Spoj/DEMSO.cpp
        Spoj/DHFRBUS.cpp
        Spoj/DTKSUB.cpp
        Spoj/DTTUI1.cpp
        Spoj/DTTUI2.cpp
        Spoj/EQSTR.cpp
        Spoj/ETF.cpp
        Spoj/FIRS.cpp
        Spoj/FLOYD.cpp
        Spoj/FSELECT.cpp
        Spoj/FWATER.cpp
        Spoj/GRAPH_.cpp
        Spoj/GSS.cpp
        Spoj/HAOI5000.cpp
        Spoj/HEAP1.cpp
        Spoj/INCVN.cpp
        Spoj/INSUL.cpp
        Spoj/IOIBIN.cpp
        Spoj/KAGAIN.cpp
        Spoj/KBUILD.cpp
        Spoj/KDIFF.cpp
        Spoj/KMIN.cpp
        Spoj/KPLANK.cpp
        Spoj/LATGACH4.cpp
        Spoj/LEM3.cpp
        Spoj/LINEGAME.cpp
        Spoj/LIQ.cpp
        Spoj/LIS.cpp
        Spoj/LITES.cpp
        Spoj/LNACS.cpp
        Spoj/LOTT.cpp
        Spoj/LQDDIV.cpp
        Spoj/LTPMSEQ.cpp
        Spoj/LUBENICA.cpp
        Spoj/M3TILE.cpp
        Spoj/MAXARR1.cpp
        Spoj/MELE3.cpp
        Spoj/MESSAGE.cpp
        Spoj/METERAIN.cpp
        Spoj/MINK.cpp
        Spoj/MMMGAME.cpp
        Spoj/MREPLBRC.cpp
        Spoj/MSE07B.cpp
        Spoj/MULONE.cpp
        Spoj/NEAREST.cpp
        Spoj/NK05MNIM.cpp
        Spoj/NKCABLE.cpp
        Spoj/NKCITY.cpp
        Spoj/NKGUARD.cpp
        Spoj/NKINV.cpp
        Spoj/NKJUMP.cpp
        Spoj/NKMAXSEQ.cpp
        Spoj/NKMOBILE.cpp
        Spoj/NKNUMFRE.cpp
        Spoj/NKPALIN.cpp
        Spoj/NKPATH.cpp
        Spoj/NKRACING.cpp
        Spoj/NKSEQ.cpp
        Spoj/NKSEV.cpp
        Spoj/NKSGAME.cpp
        Spoj/NKTOSS.cpp
        Spoj/ORDERSET.cpp
        Spoj/PALINY.cpp
        Spoj/PBCFIBO.cpp
        Spoj/PBCSEQ.cpp
        Spoj/PBCWATER.cpp
        Spoj/PNUMBER.cpp
        Spoj/POST.cpp
        Spoj/POST2.cpp
        Spoj/PTQMSEQ.cpp
        Spoj/PWALK.cpp
        Spoj/PWRFAIL.cpp
        Spoj/PYRAMID2.cpp
        Spoj/QBBUILD.cpp
        Spoj/QBHEAP.cpp
        Spoj/QBMAX.cpp
        Spoj/QBMSEQ.cpp
        Spoj/QBMST.cpp
        Spoj/QBRECT.cpp
        Spoj/QBSCHOOL.cpp
        Spoj/QBSELECT.cpp
        Spoj/QBSEQ.cpp
        Spoj/QBSQUARE.cpp
        Spoj/QHROAD.cpp
        Spoj/QMAX.cpp
        Spoj/QMAX2.cpp
        Spoj/ROADS.cpp
        Spoj/ROTATION.cpp
        Spoj/SEC.cpp
        Spoj/SHHV.cpp
        Spoj/SOPENP.cpp
        Spoj/SPBINARY.cpp
        Spoj/SPSEQ.cpp
        Spoj/SUBSTR.cpp
        Spoj/SUPERSUM.cpp
        Spoj/TCDFZ.cpp
        Spoj/THEME.cpp
        Spoj/TJALG.cpp
        Spoj/TTRIP.cpp
        Spoj/TWO.cpp
        Spoj/V8ORG.cpp
        Spoj/VBOARD.cpp
        Spoj/VCOLDWAT.cpp
        Spoj/VCOWFLIX.cpp
        Spoj/VDANGER.cpp
        Spoj/VMDAOBIT.cpp
        Spoj/VSTEPS.cpp
        Spoj/WCALC.cpp
        Spoj/WORDCNT.cpp
        String/cprefix.cpp
        String/kmp.cpp
        String/z.cpp
        Temp_f/BLGEN.cpp
        Temp_f/BWPOINTS.cpp
        Temp_f/CHESSCBG.cpp
        Temp_f/CPCRC1C.cpp
        Temp_f/dttui2.cpp
        Temp_f/HnUVA.cpp
        Temp_f/linegame.cpp
        Temp_f/MREPLBRC.cpp
        Temp_f/NKSGAME.cpp
        Temp_f/pairoftopics.cpp
        "Thay Vong/sp05-slidingwindow/differencek.cpp"
        "Thay Vong/sp05-slidingwindow/lightroad.cpp"
        "Thay Vong/sp05-slidingwindow/oewin.cpp"
        "Thay Vong/sp05-slidingwindow/oil.cpp"
        "Thay Vong/sp05-slidingwindow/s26.cpp"
        "Thay Vong/sp05-slidingwindow/spass.cpp"
        "Thay Vong/sp06/dovat.cpp"
        "Thay Vong/sp06/mpalin.cpp"
        "Thay Vong/sp06/pilseq.cpp"
        "Thay Vong/sp06/select.cpp"
        "Thay Vong/sp06/selectset.cpp"
        "Thay Vong/sp06/tent.cpp"
        "Thay Vong/sp07/apple.cpp"
        "Thay Vong/sp07/bonus.cpp"
        "Thay Vong/sp07/game.cpp"
        "Thay Vong/sp07/pseq.cpp"
        "Thay Vong/sp07/sortbook.cpp"
        "Thay Vong/sp08/divboard.cpp"
        "Thay Vong/sp08/karr.cpp"
        "Thay Vong/sp08/maxseq.cpp"
        "Thay Vong/sp08/recmin.cpp"
        "Thay Vong/sp08/shortseq.cpp"
        "Thay Vong/sp08/subarr.cpp"
        "Thay Vong/sp08/subrectmax.cpp" "Data Structure/Trie/maxxor.cpp")
