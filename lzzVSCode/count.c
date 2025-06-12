#include <linux/module.h>    // 内核模块必需的头文件
#include <linux/kernel.h>    // 常用内核函数
#include <linux/init.h>      // 初始化和退出宏
#include <linux/kthread.h>   // 内核线程相关
#include <linux/delay.h>     // 延时函数
#include <linux/sched.h>     // task_struct定义

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Enhanced Kernel Thread Example");
MODULE_VERSION("1.1");

// 全局线程指针
static struct task_struct *my_thread;

/​**​
 * @brief 线程执行函数
 * @param data 可选的线程参数（本例未使用）
 * @return 线程退出状态码
 * 
 * 每2秒打印一次计数器和当前PID，直到收到停止信号
 */
static int thread_func(void *data)
{
    int count = 0;
    
    // 主循环：检查停止信号
    while (!kthread_should_stop()) {
        // 打印线程信息（包含计数和PID）
        printk(KERN_INFO "Thread[%s] running - Count: %d, PID: %d\n", 
               current->comm, count++, current->pid);
               
        // 休眠2秒（非忙等待）
        msleep(2000);
    }
    
    // 线程终止日志
    printk(KERN_INFO "Thread[%s] cleanly stopped\n", current->comm);
    return 0;
}

/​**​
 * @brief 模块初始化函数
 * @return 0成功，错误码失败
 */
static int __init my_init(void)
{
    printk(KERN_INFO "Initializing kernel thread module\n");
    
    // 创建并启动线程（命名为"my_kthread"）
    my_thread = kthread_run(thread_func, NULL, "my_kthread");
    
    // 错误处理
    if (IS_ERR(my_thread)) {
        int err = PTR_ERR(my_thread);
        printk(KERN_ERR "Thread creation failed: %d\n", err);
        return err;
    }
    
    printk(KERN_INFO "Thread created (Task struct @ %p)\n", my_thread);
    return 0;
}

/​**​
 * @brief 模块退出函数
 */
static void __exit my_exit(void)
{
    printk(KERN_INFO "Module unloading...\n");
    
    if (my_thread && !IS_ERR(my_thread)) {
        // 优雅停止线程
        kthread_stop(my_thread);
        printk(KERN_INFO "Thread stop signal sent\n");
    }
    
    printk(KERN_INFO "Module unloaded\n");
}

// 注册生命周期回调
module_init(my_init);
module_exit(my_exit);