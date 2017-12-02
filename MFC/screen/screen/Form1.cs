using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO;

namespace screen
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized; //最小化当前窗口           
            Thread.Sleep(2000);//延时2秒                    
            if (!Directory.Exists("D:\\屏幕截图"))
            {  //判断目录是否存在,不存在就创建    
                DirectoryInfo directoryInfo = new DirectoryInfo("D:\\屏幕截图");
                directoryInfo.Create();
            }            //创建图片对象    
            Bitmap bmp2 = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height);
            Graphics g2 = Graphics.FromImage(bmp2);  //创建画笔          
            g2.CopyFromScreen(new Point(0, 0), new Point(0, 0), bmp2.Size);//截屏   
            string time = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss:fff");//获得系统时间 
            time = System.Text.RegularExpressions.Regex.Replace(time, @"[^0-9]+", "");//提取数字          
            string fileName = time + ".bmp"; //创建文件名        
            bmp2.Save("D:\\屏幕截图\\" + fileName); //保存为文件  ,注意格式是否正确.   
            bmp2.Dispose();//关闭对象      

            g2.Dispose();//关闭画笔        }    }
        }
    }
}
