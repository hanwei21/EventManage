using EventSendBridge;
using System;
using System.Windows.Forms;

namespace EventSendExe
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            EventSendClass sclass = new EventSendClass();
            sclass.SendEvent1 += Sclass_SendEvent1;
            sclass.SendEvent2 += Sclass_SendEvent2;
            sclass.SetSendEvent1();
            sclass.SetSendEvent2();
        }

        private void Sclass_SendEvent2(object sender, EventArgs e)
        {

        }

        private void Sclass_SendEvent1(object sender, EventArgs e)
        {
        }
    }
}
