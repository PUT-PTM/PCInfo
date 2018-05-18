using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Management;
using System.Management.Instrumentation;
using System.IO.Ports;
using System.Threading;
using System.Collections;
using OpenHardwareMonitor.Hardware;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort _serialPort = new SerialPort(); 
        UpdateVisitor updateVisitor = new UpdateVisitor(); 
        Computer computer = new Computer();

        public MainWindow()
        {
            InitializeComponent();
            foreach (string s in SerialPort.GetPortNames())
            {
                nrPortu.Items.Add(s);
            }
        }

        public class UpdateVisitor : IVisitor
        {
            public void VisitComputer(IComputer computer)
            {
                computer.Traverse(this);
            }
            public void VisitHardware(IHardware hardware)
            {
                hardware.Update();
                foreach (IHardware subHardware in hardware.SubHardware) subHardware.Accept(this);
            }
            public void VisitSensor(ISensor sensor) { }
            public void VisitParameter(IParameter parameter) { }
        }


        private void btn_refresh_Click(object sender, RoutedEventArgs e)
        {
            nrPortu.Items.Clear();
            foreach (string s in SerialPort.GetPortNames())
            {
                nrPortu.Items.Add(s);
            }
        }

        private void openPort_Click(object sender, RoutedEventArgs e)
        {

            try
            {
                _serialPort.PortName = nrPortu.Text;
                _serialPort.BaudRate = Int32.Parse(baudRate.Text);
                _serialPort.Parity = Parity.None;
                _serialPort.DataBits = 8;
                _serialPort.StopBits = StopBits.One;
                _serialPort.Handshake = Handshake.None;
                _serialPort.Open();
                if (_serialPort.IsOpen)
                {
                    txt_Port.Text = "Port " + nrPortu.Text + " otwarty";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Nie wybrano portu, lub port jest otwarty!\n" + ex.ToString());
            }
        }
        private void btn_Close_Click(object sender, RoutedEventArgs e)
        {
            _serialPort.Close();
            txt_Port.Text = "Port " + _serialPort.PortName + " zamknięty";
        }

        private void Window_Closed(object sender, EventArgs e)
        {
            if (_serialPort.IsOpen)
            {
                _serialPort.Close();
            }
        }

        private void btn_Send_Click(object sender, RoutedEventArgs e)
        {
            while (_serialPort.IsOpen)
            {
                GetInfo();
                Thread.Sleep(1000);
            }
        }

        public void GetInfo()
        {
                string data = "";
                computer.Open();
                computer.CPUEnabled = true;
                computer.FanControllerEnabled = true;
                computer.GPUEnabled = true;
                computer.HDDEnabled = true;
                computer.MainboardEnabled = true;
                computer.RAMEnabled = true;
                computer.Accept(updateVisitor);
                for (int i = 0; i < computer.Hardware.Length; i++)
                {
                    for (int j = 0; j < computer.Hardware[i].Sensors.Length; j++)
                    {
                        data += computer.Hardware[i].Sensors[j].Name + " : " + (int)computer.Hardware[i].Sensors[j].Value + "_";
                    }
                }
                _serialPort.Write(data);
            MessageBox.Show(data);
                computer.Close();
            
        }
    }
}