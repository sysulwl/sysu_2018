# 调研资料 - -
添加调试信息
如果您需要调试应用程序，请在编译命令行中添加-g选项。 例如：

$ mpiicc -g test.c -o testc
这会将调试信息添加到生成的二进制文件中，使您能够调试应用程序。 调试信息也被英特尔®跟踪分析器和收集器等分析工具用于显示源代码中应用程序功能的位置。


运行MPI程序
在运行MPI程序之前，请将其放置到共享位置，并确保可以从所有群集节点访问它。或者，您可以在所有节点上拥有程序的本地副本。在这种情况下，请确保程序的路径匹配。

### mpiexec.hydra
Intel建议使用`mpirun`

默认情况下，intel mpi编译器生成的可执行文件与多线程优化库链接。

瓶颈: 当前是使用Python的进程池，在一台64核机器上开启多个进程切割文件，并且进行错误检测。如果某进程挂掉了，切割的文件丢失。多进程抢占IO，且没有利用集群优势。

mpi一般要求独占cpu核，因为通信等待默认是polling。如果有别的负荷，polling时间会更多。