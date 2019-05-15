using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using TwinCAT.Ads;

namespace adsClientVisu
{
    public partial class form : Form
    {
        public form()
        {
            InitializeComponent();           
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // create a new TcClient instance          
            _tcClient = new TcAdsClient();
            adsReadStream = new AdsStream(4);
            adsWriteStream = new AdsStream(4);
        }

        /*
         * Connect the client to the local AMS router 
         */

        private void btConnect_Click(object sender, EventArgs e)
        {
            AmsAddress serverAddress = null;
            try
            {
                // check if port is a hex value
                if (tbPort.Text.StartsWith(("0x")) || tbPort.Text.StartsWith(("0X")))
                {
                    string sHexValue = tbPort.Text.Substring(2);
                    serverAddress = new AmsAddress(tbNetId.Text, Int32.Parse(sHexValue, System.Globalization.NumberStyles.HexNumber));
                }
                // interpret as dec value
                else
                {
                    serverAddress = new AmsAddress(tbNetId.Text, Int32.Parse(tbValue.Text));
                }

            }
            catch
            {
                MessageBox.Show("Invalid AMS NetId or Ams port");
                return;
            }

            try
            {
                _tcClient.Connect(serverAddress.NetId, serverAddress.Port);
                lbOutput.Items.Add("Client port " + _tcClient.ClientPort + " opened");
                lbOutput.SelectedIndex = lbOutput.Items.Count - 1;

            }
            catch
            {
                MessageBox.Show("Could not connect client");
            }
        }

        private void btStart_Click(object sender, EventArgs e)
        {
            try
            {
                _tcClient.ReadWrite(0x1, 0x1, adsReadStream, adsWriteStream);
                byte[] dataBuffer = adsReadStream.ToArray();
                lbOutput.Items.Add("Counter started value = " + BitConverter.ToUInt32(dataBuffer, 0));
                lbOutput.SelectedIndex = lbOutput.Items.Count - 1;

            }
            
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
            
        }

        private void btRead_Click(object sender, EventArgs e)
        {
            try
            {
                _tcClient.ReadWrite(0x1, 0x2, adsReadStream, adsWriteStream);
                byte[] dataBuffer = adsReadStream.ToArray();
                lbOutput.Items.Add("Counter = " + BitConverter.ToUInt32(dataBuffer, 0));
                lbOutput.SelectedIndex = lbOutput.Items.Count - 1;

            }

            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void btStop_Click(object sender, EventArgs e)
        {
            try
            {
                _tcClient.ReadWrite(0x2, 0x1, adsReadStream, adsWriteStream);
                byte[] dataBuffer = adsReadStream.ToArray();
                lbOutput.Items.Add("Counter stopped value = " + BitConverter.ToUInt32(dataBuffer, 0));
                lbOutput.SelectedIndex = lbOutput.Items.Count - 1;

            }

            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void btReset_Click(object sender, EventArgs e)
        {
            try
            {
                _tcClient.ReadWrite(0x2, 0x2, adsReadStream, adsWriteStream);
                byte[] dataBuffer = adsReadStream.ToArray();
                lbOutput.Items.Add("Counter reset Value = " + BitConverter.ToUInt32(dataBuffer, 0));
                lbOutput.SelectedIndex = lbOutput.Items.Count - 1;
            }

            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void btOverwrite_Click(object sender, EventArgs e)
        {
            try
            {      
                AdsBinaryWriter binWriter = new AdsBinaryWriter(adsWriteStream);
                adsWriteStream.Position = 0;
                
                binWriter.Write(uint.Parse(tbValue.Text));
                _tcClient.ReadWrite(0x3, 0x1, adsReadStream, adsWriteStream);
                byte[] dataBuffer = adsReadStream.ToArray();
                lbOutput.Items.Add("Counter overwritten with Value = " + BitConverter.ToUInt32(dataBuffer, 0));
                lbOutput.SelectedIndex = lbOutput.Items.Count - 1;

            }

            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        private void lbOutput_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        } 
    }
}
